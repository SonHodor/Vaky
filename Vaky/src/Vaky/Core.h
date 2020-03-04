#pragma once

#ifdef VK_PLATFORM_WINDOWS
	#ifdef VK_BUILD_DLL
		#define VAKY_API __declspec(dllexport)
	#else
		#define VAKY_API __declspec(dllimport)
	#endif
#else
	#error Vaky only supports Windows!
#endif // VK_PLATFORM_WINDOWS