include "Dependencies.lua"

workspace "NLR"
	platforms { "x86", "AMD64" }
    configurations { "Debug", "Release" }

	objdir ("%{wks.location}/.obj/%{prj.name}")
	targetdir("%{wks.location}/.bin/%{prj.name}")

    flags {
        "MultiProcessorCompile"
    }

	filter { "platforms:x86" }
    	architecture "x86"

	filter { "platforms:AMD64" }
    	architecture "x86_64"

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

    filter "configurations:Release"
		defines { "RELEASE", "NDEBUG" }
		runtime "Release"
		optimize "on"

--group "Dependencies"
--group ""

group "Core"
	include "nlr"
group ""

group "Tests"
	include "tests/alloc"
group ""