#pragma once
#include "Dompch.h"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace DoM{
	class DOM_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){return s_CoreLogger;}
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	
}

#define DOM_CORE_ERROR(...)   ::DoM::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DOM_CORE_INFO(...)    ::DoM::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DOM_CORE_TRACE(...)   ::DoM::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DOM_CORE_WARN(...)    ::DoM::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DOM_CORE_CRITICAL(...) ::DoM::Log::GetCoreLogger()->critical(__VA_ARGS__)
// Client log macros
#define DOM_TRACE(...)        ::DoM::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DOM_INFO(...)         ::DoM::Log::GetClientLogger()->info(__VA_ARGS__)
#define DOM_WARN(...)         ::DoM::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DOM_ERROR(...)        ::DoM::Log::GetClientLogger()->error(__VA_ARGS__)
#define DOM_CRITICAL(...)     ::DoM::Log::GetClientLogger()->critical(__VA_ARGS__)