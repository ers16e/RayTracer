#include "Ray.h"
#include <glm/detail/func_geometric.inl>


Ray::Ray(const glm::vec3& origin, const glm::vec3& direction): Origin(origin), Direction(direction)
{
	Direction = glm::normalize(direction);
}

Ray::~Ray()
{
}
