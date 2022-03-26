#include "Dompch.h"
#include "Platform/OpenGl/OpenGLVertexArray.h"
#include <glad/glad.h>
namespace DoM {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
		switch (type) {
		case DoM::ShaderDataType::None: return GL_FLOAT;
		case DoM::ShaderDataType::Float: return GL_FLOAT;
		case DoM::ShaderDataType::Float2: return GL_FLOAT;
		case DoM::ShaderDataType::Float3: return GL_FLOAT;
		case DoM::ShaderDataType::Float4: return GL_FLOAT;
		case DoM::ShaderDataType::Mat3: return GL_FLOAT;
		case DoM::ShaderDataType::Mat4: return GL_FLOAT;
		case DoM::ShaderDataType::Int: return GL_INT;
		case DoM::ShaderDataType::Int2: return GL_INT;
		case DoM::ShaderDataType::Int3: return GL_INT;
		case DoM::ShaderDataType::Int4: return GL_INT;
		case DoM::ShaderDataType::Bool: return GL_BOOL;
		}
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();
		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		DOM_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer without a layout.");
		for (auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);

	}

	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBuffers = indexBuffer;
	}


	const std::shared_ptr<DoM::IndexBuffer>& OpenGLVertexArray::GetIndexBuffer()
	{
		return m_IndexBuffers;
	}

	const std::vector<std::shared_ptr<DoM::VertexBuffer>>& OpenGLVertexArray::GetVertexBuffers()
	{
		return m_VertexBuffers;
	}

}