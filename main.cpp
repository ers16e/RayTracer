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
	config.Width = 1280;
	config.Height = 720;
	//TODO add filename to config

	Scene scene(config);
	
	scene.AddObject(new Sphere(1, glm::vec3(-2, -1, -6), glm::vec3(0, 100, 0)));
	scene.AddObject(new Sphere(0.5, glm::vec3(3, 0, -5), glm::vec3(45, 45, 125)));
	scene.AddObject(new Box(glm::vec3(-7, -4, -10), glm::vec3(7, -3, -3), glm::vec3(150,100,100)));
	scene.AddLight(new Light(glm::vec3(0,5,-4), glm::vec3(1, 1, 1), 1));
	scene.Render(1);
	system("pause");

}
