#pragma once
#include <glm/detail/type_vec3.hpp>

class SceneObject;

class Hit
{
public:
	Hit();
	~Hit();
	bool Success;
	float Time0;
	float Time1;
	glm::vec3 Position;
	glm::vec3 Normal;
	SceneObject *Object;
};

