#pragma once
#include "image.h"

class Operation {
public:
	static Image DilatationOrErosion(Image inputImage, int size, bool isErosion);
	static Image Resizing(Image inputImage, float factor, int width, int height);
	static Image BrightnessChange(Image inputImage, float factor, bool isBrightness);
	//static Image Stitching(Image* images);
	//static Image CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel);
};
