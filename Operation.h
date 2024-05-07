#pragma once
#include "image.h"

class Operation {
public:
	static Image DilatationOrErosion(Image inputImage, int erosionSize);
	static Image Resizing(Image inputImage, int factor);
	static Image BrightnessChange(Image inputImage, int factor);
	static Image Stitching(Image* images);
	static Image CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel);
};
