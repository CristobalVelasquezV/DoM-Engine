#pragma once

#include "DoM/Renderer/Buffer.h"
#include <memory>
namespace DoM {
	class VertexArray {
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;

		virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() = 0;
		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() = 0;

		static VertexArray* Create();
	};
}

