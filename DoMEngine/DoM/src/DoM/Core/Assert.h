#pragma once

#include "DoM/Core/Base.h"
#include "DoM/Log.h"
#include <filesystem>

#ifdef DOM_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define DOM_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { DOM##type##ERROR(msg, __VA_ARGS__); DOM_DEBUGBREAK(); } }
#define DOM_INTERNAL_ASSERT_WITH_MSG(type, check, ...) DOM_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define DOM_INTERNAL_ASSERT_NO_MSG(type, check) DOM_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", DOM_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define DOM_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define DOM_INTERNAL_ASSERT_GET_MACRO(...) DOM_EXPAND_MACRO( DOM_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, DOM_INTERNAL_ASSERT_WITH_MSG, DOM_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define DOM_ASSERT(...) DOM_EXPAND_MACRO( DOM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define DOM_CORE_ASSERT(...) DOM_EXPAND_MACRO( DOM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define DOM_ASSERT(...)
#define DOM_CORE_ASSERT(...)
#endif