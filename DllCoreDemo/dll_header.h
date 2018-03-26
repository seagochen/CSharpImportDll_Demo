#pragma once

#ifndef _HEADER_H_
#define _HEADER_H_

#include "typedefine.h" /* import external headers */

#ifndef MS_CPP_API_EXPORTS
#define MS_API __declspec(dllexport) 
#else
#define MS_API __declspec(dllimport) 
#endif


#ifdef __cplusplus    /*C++�����������ĺ꣬������g++����ʱ���ú�ʹ��ڣ�����������extern "C"�Żᱻִ��*/  
extern "C" {          /*C++����������֧�֣�C��������֧��*/
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