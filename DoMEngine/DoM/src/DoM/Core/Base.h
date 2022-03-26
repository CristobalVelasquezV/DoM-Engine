#pragma once

#include <memory>


#ifdef DOM_DEBUG
#if defined(DOM_PLATFORM_WINDOWS)
#define DOM_DEBUGBREAK() __debugbreak()
#elif defined(DOM_PLATFORM_LINUX)
#include <signal.h>
#define DOM_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define DOM_ENABLE_ASSERTS
#else
#define DOM_DEBUGBREAK()
#endif

#define DOM_EXPAND_MACRO(x) x
#define DOM_STRINGIFY_MACRO(x) #x

namespace DoM {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "DoM/Log.h"
#include "DoM/Core/Assert.h"