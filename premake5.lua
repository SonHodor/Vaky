workspace "Vaky"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Vaky"

    location "Vaky"
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
            "VK_PLATFORM_WINDOWS",
            "VK_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "VK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "VK_RELEASE"
        optimize "On"

    filter "configurations:Debug"
        defines "VK_DIST"
        optimize "On"  


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Vaky/vendor/spdlog/include;",
        "Vaky/src;"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "VK_PLATFORM_WINDOWS"
        }

    links
    {
        "Vaky"
    }    

    filter "configurations:Debug"
        defines "VK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "VK_RELEASE"
        optimize "On"

    filter "configurations:Debug"
        defines "VK_DIST"
        optimize "On"