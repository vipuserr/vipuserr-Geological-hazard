#pragma once 


#ifdef GM_KERNEL_APP_LIB
	#define GM_KERNEL_APP_EXP __declspec(dllexport)
#else
	#define GM_KERNEL_APP_EXP __declspec(dllimport)
#endif



#ifndef GM_KERNEL_APP_LIB 
	#pragma comment(lib, "gmKernelApp.lib")
#endif
