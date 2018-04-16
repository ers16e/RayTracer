#pragma once
#include "SceneObject.h"
class Light
{
public:
	Light(const glm::vec3 &position, const glm::vec3 &color, const float &intensity);

	const glm::vec3 &GetPosition() const;
	const glm::vec3 &GetColor() const;
	const float &GetIntensity() const;

	~Light();

private:
	glm::vec3 mPosition;
	glm::vec3 mColor;
	float mIntensity;
};

