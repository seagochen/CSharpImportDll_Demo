#include "dll_header.h"
#if _WIN32
#include "win_lib_link.h"
#endif

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

// delegate data put here
static IntPtr frame;

#if _WIN32
MS_API
#endif
IntPtr load_image_source(const char* filename)
{
	frame = new Mat(imread(filename));
	return frame;
}


#if _WIN32
MS_API
#endif
void extract_image_info(int* width, int* height, int* channel)
{
	Mat* ptr = (Mat*)frame;
	*width = ptr->cols;
	*height = ptr->rows;
	*channel = ptr->channels();
}


#if _WIN32
MS_API
#endif 
void display_image()
{
	Mat* ptr = (Mat*)frame;
	cv::namedWindow("demo");
	cv::imshow("demo", *ptr);
	cv::waitKey(0);
}


#if _WIN32
MS_API
#endif
void release()
{
	if (frame != nullptr) delete(frame);
}


#if _WIN32
MS_API
#endif
void update_struct(IntPtr frame, FrameInfo * info)
{
	if (info == nullptr) info = new FrameInfo();
	Mat* ptr = (Mat*)frame;

	info->width = ptr->cols;
	info->height = ptr->rows;
	info->channels = ptr->channels();
	info->size = info->width * info->height * ptr->elemSize1();
}