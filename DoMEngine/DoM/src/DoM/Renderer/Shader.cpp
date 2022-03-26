#include "Dompch.h"
#include "DoM/Renderer/Shader.h"
#include "glad/glad.h"
#include <string>
#include <glm/gtc/type_ptr.hpp>
#include "Renderer.h"
#include "Platform/OpenGl/OpenGLShader.h"
namespace DoM {


	Ref<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    DOM_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
		}           

		DOM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}