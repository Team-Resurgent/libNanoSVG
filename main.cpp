#include <cstdarg>
#include <cstring>
#include <iostream>

#define NANOSVG_IMPLEMENTATION
#include "nanosvg/nanosvg.h"
#define NANOSVGRAST_IMPLEMENTATION
#include "nanosvg/nanosvgrast.h"

#include "main.h"

int RenderSVG(const uint8_t* svg_data, uint8_t* image_data, uint16_t width, uint16_t height, uint16_t scale_factor)
{
    int pitch = width * 4;

    NSVGimage* image = nsvgParse((char*)svg_data, "px", 96.0f);
    NSVGrasterizer* rasterizer = nsvgCreateRasterizer();
    float scale = (height / image->height) / scale_factor;
    nsvgRasterize(rasterizer, image, (width - (image->width * scale)) / 2, (height - (image->height * scale)) / 2, scale, (unsigned char *)image_data, width, height, pitch);
    nsvgDeleteRasterizer(rasterizer);
    nsvgDelete(image);
    return 1;
}