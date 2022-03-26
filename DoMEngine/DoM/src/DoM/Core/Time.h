#pragma once

namespace DoM {
	class Time {

	private:
		static float deltaTime;
	public:
		static float GetDeltaTime() {
			return deltaTime;
		}
		static void Tick();

	private:
		static float m_LastFrameTime;
	};
}