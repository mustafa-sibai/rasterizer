#pragma once
#include <iostream>
#include <fstream>

#pragma pack(push,1)
struct Pixel
{
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

	Pixel() = default;

	Pixel(const uint8_t& r, const uint8_t& g, const uint8_t& b) :
		r(r), g(g), b(b)
	{
	}
};

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

struct PixelsData
{
	Pixel* rowOfPixels = nullptr;
	int16_t padding = 0;
};

struct BMPImage
{
	BMPHeader bmpHeader;
	DIPHeader dipHeader;
	PixelsData* pixelsData = nullptr;

	BMPImage(int32_t imageWidth, int32_t imageHeight, PixelsData* pixelsData) :
		pixelsData(pixelsData)
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
	void WriteBMPFile(BMPImage& bmp);
};