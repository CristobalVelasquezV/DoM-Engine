#pragma once
#include "RendererAPI.h"
#include "Shader.h"
#include "OrthographicCamera.h"
#include "glm/glm.hpp"
namespace DoM {

	class Renderer {
	public:

		static void EndScene();
		static void BeginScene(OrthographicCamera& camera);
		static void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform);

		static inline RendererAPI::API GetAPI() {
			return RendererAPI::GetAPI();
		}
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* s_SceneData;
	};
	
}