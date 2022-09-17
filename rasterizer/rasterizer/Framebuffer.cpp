#include "Framebuffer.h"

Framebuffer::Framebuffer(int width, int height) :
	pixels(nullptr), width(width), height(height)
{
	if (width <= 0 || height <= 0)
	{
		std::cout << "Framebuffer width or height cannot be less than or equal to zero" << std::endl;
		return;
	}

	pixels = new Pixel[width * height];
}

Framebuffer::~Framebuffer()
{
}