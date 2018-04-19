#include "Box.h"



Box::Box(const glm::vec3& minVec, const glm::vec3& maxVec,const glm::vec3 &color): SceneObject(minVec, color)
{
	bounds[0] = minVec;
	bounds[1] = maxVec;
}

Box::~Box()
{
}


//Smit's Method
Hit Box::Intersect(const Ray& ray)
{
	float tmin = (bounds[ray.sign[0]].x - ray.Origin.x) * ray.Inverse.x;
	float tmax = (bounds[1 - ray.sign[0]].x - ray.Origin.x) * ray.Inverse.x;
	float tymin = (bounds[ray.sign[1]].y - ray.Origin.y) * ray.Inverse.y;
	float tymax = (bounds[1 - ray.sign[1]].y - ray.Origin.y) * ray.Inverse.y;
	Hit hit;
	if(tmin > tymax || tymin > tmax)
	{
		hit.Success = false;
		return hit;
	}
	if(tymin > tmin)
	{
		tmin = tymin;
	}
	if(tymax < tmax)
	{
		tmax = tymax;
	}

	float tzmin = (bounds[ray.sign[2]].z - ray.Origin.z) * ray.Inverse.z;
	float tzmax = (bounds[1 - ray.sign[2]].z - ray.Origin.z) * ray.Inverse.z;
	if(tmin > tzmax || tzmin > tmax)
	{
		hit.Success = false;
		return hit;
	}
	if(tzmin > tmin)
	{
		tmin = tzmin;
	}
	if(tzmax < tmax)
	{
		tmax = tzmax;
	}
	
	if(tmin < 0)
	{
		if(tmax < 0)
		{
			hit.Success = false;
			return hit;
		}
		hit.Time0 = tmax;
		hit.Time1 = tmin;
	}
	else
	{
		hit.Time0 = tmin;
		hit.Time1 = tmax;
	}
	hit.Success = true;
	hit.Object = this;
	
	return hit;
}
