#pragma once
#include <iostream>
#include <fstream>
#include "Pixel.h"

#pragma pack(push,1)
struct DIPHeader
{
	int32_t dipHeaderSize = sizeof(DIPHeader);
	int32_t imageWidth = 0;
	int32_t imageHeight = 0;
	int16_t colorPlanes = 1;
	int16_t bitsPerPixel = 24;
	int32_t pixelCompression = 0;
	int32_t sizeOfRawBitmapDataWithPadding = 0;
	int32_t horizontalPrintResolution = 2835;
	int32_t verticalPrintResolution = 2835;
	int32_t colorsPerPalette = 0;
	int32_t importantColors = 0;
};

struct BMPHeader
{
	int8_t id[2];
	int32_t bmpFileSize = 0;
	int16_t unused0 = 0;
	int16_t unused1 = 0;
	int32_t offsetToPixelData = sizeof(BMPHeader) + sizeof(DIPHeader);

	BMPHeader()
	{
		id[0] = 'B';
		id[1] = 'M';
	}
};

struct BMPImage
{
	BMPHeader bmpHeader;
	DIPHeader dipHeader;

	BMPImage(int32_t imageWidth, int32_t imageHeight)
	{
		dipHeader.imageWidth = imageWidth;
		dipHeader.imageHeight = imageHeight;
	}

	inline int32_t getPixelDataSize()
	{
		return (dipHeader.imageWidth * dipHeader.imageHeight) + (sizeof(uint16_t) * dipHeader.imageHeight) * 3;
	}
};
#pragma pack(pop)

class BMPWriter
{
public:
	void WriteBMPFile(const class Framebuffer& framebuffer);
};