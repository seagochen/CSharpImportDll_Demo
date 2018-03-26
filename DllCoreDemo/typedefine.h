#pragma once
#ifndef _TYPE_DEFINE_H_
#define _TYPE_DEFINE_H_

typedef void* IntPtr;

struct FrameInfo
{
	int width;
	int height;
	int channels;
	size_t size;
};

#endif