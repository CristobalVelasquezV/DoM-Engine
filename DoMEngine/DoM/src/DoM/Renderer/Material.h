#pragma once

#include "DoM/Renderer/VertexArray.h"
#include "DoM/Renderer/Shader.h"

namespace DoM {
	class Material {
	public:
		
	
		Material(glm::vec4 color);
		void Initialize();
		void UploadMaterial();

		std::shared_ptr<VertexArray> m_VertexArray;
		Ref<Shader>  m_Shader;
		glm::vec4 m_SquareColor;
	};



}