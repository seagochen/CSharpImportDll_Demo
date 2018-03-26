#pragma once

#ifndef _HEADER_H_
#define _HEADER_H_

#include "typedefine.h" /* import external headers */

#ifndef MS_CPP_API_EXPORTS
#define MS_API __declspec(dllexport) 
#else
#define MS_API __declspec(dllimport) 
#endif


#ifdef __cplusplus    /*C++编译器包含的宏，例如用g++编译时，该宏就存在，则下面的语句extern "C"才会被执行*/  
extern "C" {          /*C++编译器才能支持，C编译器不支持*/
#endif

#if _WIN32 /* cross platform coding for windows style */

	MS_API IntPtr load_image_source(const char* filename);

	MS_API void extract_image_info(int* width, int* height, int* channel);

	MS_API void display_image();

	MS_API void release();

	MS_API void update_struct(IntPtr ptr, FrameInfo * info);
	
#elif linux /* cross platform coding for linux style */


#endif


#ifdef __cplusplus  
}
#endif


#endif