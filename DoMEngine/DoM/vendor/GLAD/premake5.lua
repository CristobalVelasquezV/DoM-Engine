project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
		"include/GLAD/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs{
		"include"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter {"configurations:Debug"}
		runtime "Debug"
		optimize "on"

	filter {"configurations:Release"}
		runtime "Release"
		optimize "on"
