#pragma once
#ifdef DOM_PLATFORM_WINDOWS
#if DOM_DYNAMIC_LINK
	#ifdef DOM_BUILD_DLL
		#define DOM_API __declspec(dllexport)
	#else
		#define DOM_API __declspec(dllimport)

	#endif // DOM_BUILD_DLL

#else
	#define  DOM_API

#endif // DOM_PLATFORM_WINDOWS
#endif
#define  BIT(x) (1 << x)

#define DOM_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)