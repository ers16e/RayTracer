#pragma once
#include <glm/vec3.hpp>
#include "SceneObject.h"


//See An Efficient and Robust Ray–Box Intersection Algorithm, A. Williams, 2004
class Box: public SceneObject
{
public:
	Box(const glm::vec3 &minVec, const glm::vec3 &maxVec, const glm::vec3 &color);
	~Box();

	Hit Intersect(const Ray &ray) override;

private:
	glm::vec3 bounds[2];

};

