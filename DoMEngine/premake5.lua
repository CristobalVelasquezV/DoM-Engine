workspace "DoM"
	architecture "x64"
	startproject "SandBox"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	-- Include directories relative to root folder 
	IncludeDir = {}
	IncludeDir["GLFW"]="%{prj.name}/vendor/GLFW/include"
	IncludeDir["GLAD"]="%{prj.name}/vendor/GLAD/include"
	IncludeDir["ImGui"]="DoM/vendor/ImGui"
	IncludeDir["glm"]="DoM/vendor/glm"

	include "DoM/vendor/GLFW"
	include "DoM/vendor/GLAD"
	include "DoM/vendor/ImGui"

	project "DoM"
		location "DoM"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "Dompch.h"
		pchsource "%{prj.name}/src/Dompch.cpp"
		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl",
		}
		includedirs{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include/",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.GLAD}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}"
		}
		links{
			"GLFW",
			"GLAD",
			"opengl32.lib",
			"ImGui"
		}
	filter "system:windows"
		systemversion "latest"

		defines{
			"DOM_PLATFORM_WINDOWS",
			"DOM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DOM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DOM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DOM_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
	}
	includedirs{
		"DoM/vendor/spdlog/include",
		"DoM/src",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",

	}
	links{
		"DoM"
	}
	filter "system:windows"
	systemversion "latest"

		defines{
			"DOM_PLATFORM_WINDOWS",
		}
	filter "configurations:Debug"
		defines "DOM_DEBUG"
		symbols "On"
		runtime "Debug"

	filter "configurations:Release"
		defines "DOM_RELEASE"
		optimize "On"
		runtime "Release"


	filter "configurations:Dist"
		defines "DOM_DIST"
		runtime "Release"
		optimize "On"
