#pragma once
#include "Pixel.h"

class Framebuffer
{
private:
	Pixel* pixels;
	int width;
	int height;

public:
	Framebuffer(int width, int height);
	~Framebuffer();

	inline Pixel* GetPixels() const { return pixels; }
	inline const int& GetWidth() const { return width; }
	inline const int& GetHeight() const { return height; }
};