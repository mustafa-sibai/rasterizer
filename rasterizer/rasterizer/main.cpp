#pragma once
#include <iostream>
#include <fstream>
#include "BMPWriter.h"

int main()
{
	PixelsData* pixelsData = new PixelsData[2];

	pixelsData[0].rowOfPixels = new Pixel[2];
	pixelsData[0].rowOfPixels[0] = Pixel(255, 0, 0);
	pixelsData[0].rowOfPixels[1] = Pixel(255, 255, 255);

	//---------------------------------------

	pixelsData[1].rowOfPixels = new Pixel[2];
	pixelsData[1].rowOfPixels[0] = Pixel(0, 0, 255);
	pixelsData[1].rowOfPixels[1] = Pixel(0, 255, 0);

	BMPImage bmpImage(2, 2, pixelsData);

	BMPWriter bmpWriter;
	bmpWriter.WriteBMPFile(bmpImage);

	return 0;
}