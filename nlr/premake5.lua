project "nlr"
    kind "SharedLib"
    language "C++"
	cppdialect "C++17"

	warnings "Everything"

    files {
		"include/**.hpp",
		"include/**.h",
		"src/**.cpp",
		"src/**.hpp",
		"src/**.h",
		"src/**.c"
    }

	defines {
	}

    includedirs {
		"include"
	}

    links {
    }

    flags { "NoPCH" }