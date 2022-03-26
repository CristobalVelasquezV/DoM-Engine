
#include "Dompch.h"
#include "Transform.h"
namespace DoM {

	Transform::Transform(const glm::vec3& translation) : Translation(translation)
	{

	}

	Transform::Transform(const glm::vec3& translation, const glm::vec3& rotation, const glm::vec3& scale):
		Translation(translation), Rotation(rotation),Scale(scale)
	{

	}

	void Transform::SetPosition(const glm::vec3& position)
	{
		Translation = position;
	}

}