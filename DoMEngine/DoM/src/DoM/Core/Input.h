#pragma once

#include "DoM/Core.h"
#include "DoM/Core/KeyCodes.h"
#include "DoM/Core/MouseCodes.h"
#include "glm/vec2.hpp"
namespace DoM {
	class DOM_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}