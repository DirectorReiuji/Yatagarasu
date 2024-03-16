#pragma once

#ifdef YG_PLATFORM_WINDOWS
	#ifdef YG_BUILD_DLL
		#define YATAGARASU_API __declspec(dllexport)
	#else
		#define YATAGARASU_API __declspec(dllimport)
	#endif
#else
	#error Yatagarasu is not available on your OS! Please use Windows for the time being.
#endif