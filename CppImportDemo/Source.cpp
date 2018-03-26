#include <dll_header.h>
#include <stdio.h>
#include <stdlib.h>

#include "win_lib_link.h"

int main()
{
	IntPtr ptr = load_image_source("test.jpg");
	if (ptr == nullptr)
	{
		printf("null");
		exit(1);
	}

	//extract_image_info(&width, &height, &channles);

	FrameInfo info;

	update_struct(ptr, &info);

	printf("\n%d %d %d %d", info.width, info.height, info.channels, info.size);

	display_image();

	release();
}