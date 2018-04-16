#include "Sphere.h"
#include <iostream>
#include <string>
#include "Scene.h"

std::string VectorString(const glm::vec3 &vector)
{
	return "<" + std::to_string(vector.x) + "," + std::to_string(vector.y) + "," + std::to_string(vector.z) + ">";
}


int main()
{
	SceneConfig config;
	config.Fov = 90;
	config.Height = 1080;
	config.Width = 1920;
	Scene scene(config);
	scene.AddLight(new Light(glm::vec3(2, 2, -10), glm::vec3(1, 1, 1), 10));
	scene.AddObject(new Sphere(2.0, glm::vec3(1, 1, -5), glm::vec3(0, 100, 0)));
	scene.AddObject(new Sphere(1.0, glm::vec3(-1, -1, -2), glm::vec3(45, 45, 125)));
	scene.Render();
}