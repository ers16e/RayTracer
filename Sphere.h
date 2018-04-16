#pragma once
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "SceneObject.h"


class Sphere : public SceneObject
{
public:
	Sphere(const double &radius, const glm::vec3 &position, const glm::vec3 &color);
	~Sphere();
	Hit Intersect(const Ray &ray)override;

	
private:
	double mRadius; // Radius of sphere
};

