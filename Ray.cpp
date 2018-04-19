#include "Ray.h"
#include <glm/detail/func_geometric.inl>


Ray::Ray(const glm::vec3& origin, const glm::vec3& direction): Origin(origin), Direction(direction)
{
	Direction = glm::normalize(direction);
	Inverse.x = 1 / Direction.x;
	Inverse.y = 1 / Direction.y;
	Inverse.z = 1 / Direction.z;
	sign[0] = Inverse.x < 0;
	sign[1] = Inverse.y < 0;
	sign[2] = Inverse.z < 0;
}

Ray::~Ray()
{
}
