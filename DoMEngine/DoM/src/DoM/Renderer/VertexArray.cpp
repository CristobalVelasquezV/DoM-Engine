#include "Dompch.h"
#include "DoM/Renderer/VertexArray.h"
#include "DoM/Renderer/Renderer.h"
#include "Platform/OpenGl/OpenGLVertexArray.h"
namespace DoM {

	DoM::VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			DOM_CORE_ASSERT(false, "RendererAPI::None currently not supported.");
			break;

		case RendererAPI::API::OpenGL:
			return new OpenGLVertexArray();

		}
	}

}