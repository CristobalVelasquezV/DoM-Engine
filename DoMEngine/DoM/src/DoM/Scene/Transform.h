#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
namespace DoM {
	class Transform {
	public:
		glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };
	
		Transform() = default;
	
		Transform(const glm::vec3& translation);
		Transform(const glm::vec3& translation, const glm::vec3& rotation, const glm::vec3& scale);
		void SetPosition(const glm::vec3& position);
		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation)
				* glm::scale(glm::mat4(1.0f), Scale);
		}
	};
}