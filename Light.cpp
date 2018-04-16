#include "Light.h"


Light::Light(const glm::vec3& position, const glm::vec3& color, const float& intensity): mPosition(position),mColor(color),mIntensity(intensity)
{
}

const glm::vec3& Light::GetPosition() const
{
	return mPosition;
}

const glm::vec3& Light::GetColor() const
{
	return mColor;
}

const float& Light::GetIntensity() const
{
	return mIntensity;
}

Light::~Light()
{
}
