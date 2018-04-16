#include "Sphere.h"
#include <cmath>


Sphere::Sphere(const double &radius, const glm::vec3 &position, const glm::vec3 &color) : SceneObject(position, color), mRadius(radius)
{
}

Sphere::~Sphere()
{
}

Hit Sphere::Intersect(const Ray& ray)
{
	Hit hit;
	glm::vec3 L = mPosition - ray.Origin;
	float tca = glm::dot(L, ray.Direction);
	if(tca < 0)
	{
		hit.Success = false;
		return hit;
	}
	float d2 = glm::dot(L, L) - std::pow(tca,2);
	if(d2 > std::pow(mRadius,2))
	{
		hit.Success = false;
		return hit;
	}
	float thc = std::sqrt(std::pow(mRadius, 2) - d2);
	hit.Time0 = tca - thc;
	hit.Time1 = tca + thc;
	hit.Success = true;
	hit.Object = this;
	return hit;
}
