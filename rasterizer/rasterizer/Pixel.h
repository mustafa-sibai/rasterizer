#pragma once
#include <iostream>

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