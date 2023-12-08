project "NiTiSLanguagesRuntime"
    kind "StaticLib"
    language "C++"
	cppdialect "C++17"

    files
	{
		"include/**.hpp",
		"src/**.cpp",
    }

	defines
	{
	}

    includedirs
	{
		"include"
	}

    links
    {

    }

    flags { "NoPCH" }

    filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

    filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"