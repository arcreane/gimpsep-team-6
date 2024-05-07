#pragma once

class Operation {
public:
	Image DilatationOrErosion(Image inputImage, int erosionSize);
	Image Resizing(Image inputImage, int factor);
	Image BrightnessChange(Image inputImage, int factor);
	Image Stitching(Image* images);
	Image CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel);
};
