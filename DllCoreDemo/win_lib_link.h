#pragma once

#ifndef LINK_NECESSARY_LIBS
#define LINK_NECESSARY_LIBS
#if _WIN32
#if _DEBUG
#pragma comment(lib, "opencv_world330d.lib")
#else
#pragma comment(lib, "opencv_world330.lib")
#endif
#endif
#endif