#include "BMPWriter.h"

void BMPWriter::WriteBMPFile(BMPImage& bmp)
{
	bmp.bmpHeader.bmpFileSize = sizeof(BMPHeader) + sizeof(DIPHeader) + bmp.getPixelDataSize();
	bmp.dipHeader.sizeOfRawBitmapDataWithPadding = bmp.getPixelDataSize();

	std::ofstream file;

	file.open("image.bmp", std::ios::out | std::ios::binary);

	file.write((char*)&bmp.bmpHeader.id[0], sizeof(int8_t));
	file.write((char*)&bmp.bmpHeader.id[1], sizeof(int8_t));
	file.write((char*)&bmp.bmpHeader.bmpFileSize, sizeof(bmp.bmpHeader.bmpFileSize));
	file.write((char*)&bmp.bmpHeader.unused0, sizeof(bmp.bmpHeader.unused0));
	file.write((char*)&bmp.bmpHeader.unused1, sizeof(bmp.bmpHeader.unused1));
	file.write((char*)&bmp.bmpHeader.offsetToPixelData, sizeof(bmp.bmpHeader.offsetToPixelData));

	file.write((char*)&bmp.dipHeader.dipHeaderSize, sizeof(bmp.dipHeader.dipHeaderSize));
	file.write((char*)&bmp.dipHeader.imageWidth, sizeof(bmp.dipHeader.imageWidth));
	file.write((char*)&bmp.dipHeader.imageHeight, sizeof(bmp.dipHeader.imageHeight));
	file.write((char*)&bmp.dipHeader.colorPlanes, sizeof(bmp.dipHeader.colorPlanes));
	file.write((char*)&bmp.dipHeader.bitsPerPixel, sizeof(bmp.dipHeader.bitsPerPixel));
	file.write((char*)&bmp.dipHeader.pixelCompression, sizeof(bmp.dipHeader.pixelCompression));
	file.write((char*)&bmp.dipHeader.sizeOfRawBitmapDataWithPadding, sizeof(bmp.dipHeader.sizeOfRawBitmapDataWithPadding));
	file.write((char*)&bmp.dipHeader.horizontalPrintResolution, sizeof(bmp.dipHeader.horizontalPrintResolution));
	file.write((char*)&bmp.dipHeader.verticalPrintResolution, sizeof(bmp.dipHeader.verticalPrintResolution));
	file.write((char*)&bmp.dipHeader.colorsPerPalette, sizeof(bmp.dipHeader.colorsPerPalette));
	file.write((char*)&bmp.dipHeader.importantColors, sizeof(bmp.dipHeader.importantColors));

	for (size_t y = 0; y < bmp.dipHeader.imageHeight; y++)
	{
		for (size_t x = 0; x < bmp.dipHeader.imageWidth; x++)
		{
			file.write((char*)&bmp.pixelsData[y].rowOfPixels[x].b, sizeof(bmp.pixelsData[y].rowOfPixels[x].b));
			file.write((char*)&bmp.pixelsData[y].rowOfPixels[x].g, sizeof(bmp.pixelsData[y].rowOfPixels[x].g));
			file.write((char*)&bmp.pixelsData[y].rowOfPixels[x].r, sizeof(bmp.pixelsData[y].rowOfPixels[x].r));
		}
		file.write((char*)&bmp.pixelsData[y].padding, sizeof(bmp.pixelsData[y].padding));
	}

	file.close();
}