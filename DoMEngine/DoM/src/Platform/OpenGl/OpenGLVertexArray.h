#pragma once
#include "DoM/Renderer/VertexArray.h"
namespace DoM {
	class OpenGLVertexArray :public VertexArray {


	public:
		OpenGLVertexArray();
		void Bind() const override;


		void Unbind() const override;

		void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer) override;

		void SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer) override;

		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() override;
		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() override;
		private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffers;

	};


}
