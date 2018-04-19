#pragma once
#include <vector>
#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include "SceneObject.h"
#include "Light.h"
#include <corecrt_math_defines.h>

struct SceneConfig
{
	float Width, Height, Fov;
};

class Scene
{
public:
	explicit Scene(SceneConfig config);
	~Scene();
	void AddObject(SceneObject *object);
	void PopLight();
	void PopObject();
	void AddLight(Light *light);
	void Render(int fileNumber);

private:
	glm::vec2 mDim;
	std::vector<SceneObject*> mObjects;
	std::vector<Light*> mLights;
	SceneConfig config;
};

