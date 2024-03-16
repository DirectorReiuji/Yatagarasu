workspace "Yatagarasu"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Yatagarasu"
	location "Yatagarasu"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"YG_PLATFORM_WINDOWS;",
			"YG_BUILD_DLL;"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "YG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Yatagarasu/vendor/spdlog/include;",
		"Yatagarasu/src"
	}

	links
	{
		"Yatagarasu"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"YG_PLATFORM_WINDOWS;"
		}

	filter "configurations:Debug"
		defines "YG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YG_DIST"
		optimize "On"