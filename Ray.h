#pragma once

#include <glm/vec3.hpp>
class Ray
{
public:
	Ray(const glm::vec3 &origin, const glm::vec3 &direction);
	~Ray();
	glm::vec3 Origin;
	glm::vec3 Direction;
	glm::vec3 Inverse;
	int sign[3];

};

