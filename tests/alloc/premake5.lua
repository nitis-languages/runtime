project "test_alloc"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"

	includedirs {
		"%{wks.location}/nlr/include"
	}

	-- Who is the idiot responsible for inventing the backslash as a directory separator on Windows?????????
	postbuildcommands { "copy /Y %{wks.location}.bin\\nlr\\nlr.dll %{wks.location}.bin\\%{prj.name}\\nlr.dll" }

	links { "nlr" }

	files { "main.cpp" }