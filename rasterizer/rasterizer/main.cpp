#pragma once
#include <iostream>
#include <fstream>
#include "BMPWriter.h"
#include "Framebuffer.h"

int main()
{
	Framebuffer framebuffer(800, 600);
	Pixel* pixels = framebuffer.GetPixels();
	Pixel* startOfArray = pixels;

	for (size_t y = 0; y < framebuffer.GetHeight(); y++)
	{
		for (size_t x = 0; x < framebuffer.GetWidth(); x++)
		{
			*pixels = Pixel(255 - 1 * y, 255 - 1 * y, 255 - 1 * y);
			pixels++;
		}
	}
	pixels = startOfArray;

	BMPWriter bmpWriter;
	bmpWriter.WriteBMPFile(framebuffer);

	return 0;
}