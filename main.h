#pragma once

#ifdef _WIN32
#define TR_EXPORT extern "C" __declspec(dllexport)
#else
#define TR_EXPORT extern "C" __attribute__((visibility("default")))
#endif

TR_EXPORT int RenderSVG(const uint8_t* svg_data, uint8_t* image_data, uint16_t width, uint16_t height, uint16_t scale_factor);