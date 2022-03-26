#include "Dompch.h"
#include "Material.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace DoM {

	Material::Material(glm::vec4 color) :m_SquareColor(color)
	{
		Initialize();
	}

	void Material::Initialize()
	{
		float vertices[3 * 4] = {
-1.0f, -1.0f, 0.0f,
 -1.0f, 1.0f, 0.0f,
 1.0f,  -1.0f, 0.0f,
 1.0f,1.0f,0.0f

		};

		std::shared_ptr<DoM::IndexBuffer> m_IndexBuffer;
		std::shared_ptr<DoM::VertexBuffer> m_VertexBuffer;
		m_VertexArray.reset(DoM::VertexArray::Create());
		m_VertexBuffer.reset(DoM::VertexBuffer::Create(vertices, sizeof(vertices)));


		DoM::BufferLayout layout = {
			{DoM::ShaderDataType::Float3,"a_Position"},
		};

		m_VertexBuffer->SetLayout(layout);

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		unsigned int indices[6] = { 0,1,2,1,2,3 };

		m_IndexBuffer.reset(DoM::IndexBuffer::Create(indices, 6));
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
			#version 410 core
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;


			out vec3 v_Position;

			void main(){
				v_Position = a_Position;
				gl_Position =u_ViewProjection*u_Transform*vec4( a_Position, 1.0);
			}
		)";
		std::string fragmentSrc = R"(
			#version 410 core
			layout(location = 0) out vec4 color;

			uniform vec4 u_Color;
			in vec3 v_Color;
			in vec3 v_Position;
			void main(){
				color = u_Color;
			}
		)";

		m_Shader = DoM::Shader::Create(vertexSrc, fragmentSrc);
		DOM_CORE_INFO("Awake Render component");
	}

	void Material::UploadMaterial()
	{
		m_Shader->SetFloat4("u_Color", m_SquareColor);
	}

}
