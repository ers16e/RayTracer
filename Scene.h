#pragma once
#include <vector>
#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include "SceneObject.h"
#include "Light.h"
#define _USE_MATH_DEFINES

struct SceneConfig
{
	int Width, Height;
	float Fov;
};

class Scene
{
public:
	explicit Scene(SceneConfig config);
	~Scene();
	void AddObject(SceneObject *object);
	void AddLight(Light *light);
	void Render();

private:
	glm::vec2 mDim;
	std::vector<SceneObject*> mObjects;
	std::vector<Light*> mLights;
	SceneConfig config;
};

