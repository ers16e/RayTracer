#include "SceneObject.h"


const glm::vec3& SceneObject::GetColor() const
{
	return mColor;
}

SceneObject::SceneObject(const glm::vec3& position, const glm::vec3 &color): mPosition(position), mColor(color)
{
}

SceneObject::~SceneObject()
{
}

std::ostream& operator<<(std::ostream& out, const SceneObject& c)
{
	out << "Object at: <" << c.mPosition.x << ", " << c.mPosition.y << ", " << c.mPosition.z << ">";
	return out;
}
