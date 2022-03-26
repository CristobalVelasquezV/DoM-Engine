#pragma once
#include "DoM/Renderer/RendererAPI.h"
namespace DoM {
	class OpenGLRendererAPI : public RendererAPI{
	
	public:
		void SetClearColor(const glm::vec4& color) override;


		void Clear() override;


		void DrawIndexed(const std::shared_ptr<VertexArray>& VertexArray) override;

	};
}