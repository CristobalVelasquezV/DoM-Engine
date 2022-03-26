#pragma once
#include "DoM/Renderer/Buffer.h"

namespace DoM {
	class OpenGLVertexBuffer: public VertexBuffer{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		virtual void Bind() const override;

		virtual void Unbind() const override;

		virtual inline const BufferLayout& GetLayout() const override;

		virtual void SetLayout(BufferLayout& layout) override;
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	
	};

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();
		virtual uint32_t GetCount() const { return m_Count; }
		virtual void Bind() const override;

		virtual void Unbind() const override;

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;


	};
}