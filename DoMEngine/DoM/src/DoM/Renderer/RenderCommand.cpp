#include "Dompch.h"
#include "RenderCommand.h"
#include "Platform/OpenGl/OpenGLRendererAPI.h"
namespace DoM {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
	
}