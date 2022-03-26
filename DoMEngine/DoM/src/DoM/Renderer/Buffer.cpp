#include "Dompch.h"
#include "DoM/Renderer/Buffer.h"
#include "DoM/Renderer/Renderer.h"
#include "Platform/OpenGl/OpenGLBuffer.h"
namespace DoM {
	
	DoM::VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			DOM_CORE_ASSERT(false, "RendererAPI::None currently not supported.");
			break;

		case RendererAPI::API::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);

		}

	}

	DoM::IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			DOM_CORE_ASSERT(false, "RendererAPI::None currently not supported.");
			break;

		case RendererAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, count);

		}
	}

}