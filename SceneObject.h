#pragma once
#include "Hit.h"
#include "Ray.h"
#include <ostream>


class SceneObject
{
public:

	virtual Hit Intersect(const Ray &ray)= 0;
	const glm::vec3 &GetColor() const;

	explicit SceneObject(const glm::vec3 &position, const glm::vec3 &color);
	virtual ~SceneObject();
	friend std::ostream & operator << (std::ostream &out, const SceneObject &c);

protected:

	glm::vec3 mPosition;
	glm::vec3 mColor;
};

