#include "Scene.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>


Scene::Scene(SceneConfig config):config(config)
{

}

Scene::~Scene()
{
	for(auto itr = mObjects.begin(); itr != mObjects.end(); ++itr)
	{
		delete *itr;
	}
	for (auto itr = mLights.begin(); itr != mLights.end(); ++itr)
	{
		delete *itr;
	}
}

void Scene::AddObject(SceneObject* object)
{
	mObjects.push_back(object);
}

void Scene::AddLight(Light* light)
{
	mLights.push_back(light);
}

void Scene::Render(int fileNumber)
{
	auto begin = std::clock();
	float width = config.Width;
	float height = config.Height;
	float aspectRatio = width / height;
	float fov = config.Fov;
	glm::vec3 *image = new glm::vec3[width*height];
	int counter = 0;
	for (int y = 0; y < height; ++y)
	{
		for(int x = 0; x < width; ++x)
		{
			float px = (2 * ((x + 0.5) / width) - 1)*std::tan(fov / 2 * M_PI / 180) * aspectRatio;
			float py = 1 - 2 * ((y + 0.5) / height)*std::tan(fov / 2 * M_PI / 180);
			Ray primaryRay(glm::vec3(0,0,0),glm::vec3(px,py,-1));
			float minTime = 1e8;
			SceneObject *minObject = nullptr;
			for(auto itr = mObjects.begin(); itr != mObjects.end();++itr)
			{

				Hit hit = (*itr)->Intersect(primaryRay);
				if (hit.Success)
				{
					if(hit.Time0 < minTime)
					{
						minTime = hit.Time0;
						minObject = hit.Object;
					}
				}
			}
			if(minObject != nullptr)
			{
				glm::vec3 hitPosition = primaryRay.Origin + primaryRay.Direction * minTime;
				glm::vec3 objectColor = minObject->GetColor();
				glm::vec3 netIllumination(0, 0, 0);
				for(auto itr = mLights.begin(); itr != mLights.end(); ++itr)
				{
					glm::vec3 currentIllumination(0, 0, 0);
					Ray shadowRay(hitPosition,(*itr)->GetPosition() - hitPosition);
					float distance = glm::distance(hitPosition, (*itr)->GetPosition());
					bool inShadow = false;
					for(auto itr2 = mObjects.begin(); itr2 != mObjects.end(); ++itr2)
					{
						Hit hit = (*itr2)->Intersect(shadowRay);

						if(hit.Success)
						{
							if(hit.Time0 < distance)
							{
								inShadow = true;
								break;
							}
						}
						
					}
					if(!inShadow)
					{
						float intens = (*itr)->GetIntensity();
						currentIllumination = glm::vec3(intens, intens, intens);
					}
					netIllumination += currentIllumination;
				}
				image[counter++] = minObject->GetColor() * netIllumination;
			}
			else
			{
				image[counter++] = glm::vec3(255, 255, 255);
			}
		}
	}
	auto endClock = std::clock();
	double elapsed_secs = double(endClock - begin) / CLOCKS_PER_SEC;
	std::cout << "FPS: " << 1 / elapsed_secs << std::endl;
	std::string path = "./Render/out" + std::to_string(fileNumber) + ".ppm";
	std::ofstream ofs(path, std::ios::out | std::ios::binary);
	ofs << "P6\n" << config.Width << " " << config.Height << "\n255\n";
	if(!ofs.is_open())
	{
		std::cout << "WTF" << std::endl;
	}
	for (uint32_t i = 0; i < config.Height * config.Width; ++i) {
		char r = (char)(image[i].r);
		char g = (char)(image[i].g);
		char b = (char)(image[i].b);
		ofs << r << g << b;
	}

	ofs.close();
	delete[] image;

}

void Scene::PopLight()
{
	delete *(mLights.end() - 1);
	mLights.pop_back();
}

void Scene::PopObject()
{
	delete (*mObjects.end()-1);
	mObjects.pop_back();
}
