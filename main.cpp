#include "Sphere.h"
#include <iostream>
#include <string>
#include "Scene.h"
#include <glm/vec3.hpp>
#include "Box.h"

std::string VectorString(const glm::vec3 &vector)
{
	return "<" + std::to_string(vector.x) + "," + std::to_string(vector.y) + "," + std::to_string(vector.z) + ">";
}


int main()
{
	SceneConfig config;
	config.Fov = 90;
	config.Width = 1920;
	config.Height = 1080;
	//TODO add filename to config

	Scene scene(config);
	
	scene.AddObject(new Sphere(2.0, glm::vec3(-2, 1, -6), glm::vec3(0, 100, 0)));
	scene.AddObject(new Sphere(1.0, glm::vec3(2, 0, -6), glm::vec3(45, 45, 125)));
	scene.AddObject(new Box(glm::vec3(-5, -3, -10), glm::vec3(5, -2, -5), glm::vec3(250,200,200)));
	scene.AddLight(new Light(glm::vec3(0,2,-5), glm::vec3(1, 1, 1), 1));
	scene.Render(1);
	system("pause");

}
