#pragma once
#include "image.h"

class Operation {
public:
	static Image DilatationOrErosion(Image inputImage, int size, bool isErosion);
	static Image Resizing(Image inputImage, float factor, int width, int height);
	static Image BrightnessChange(Image inputImage, float factor, bool isBrightness);
	static Image Stitching(vector<Mat> inputImages);
	static Image CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel);
	static Image Crop(Image inputImage, int ymin, int ymax, int xmin, int xmax);
	static Image Rotation(Image inputImage, double rotationAngle);
	static Image ChangeColor(Image inputImage, int colorVariation);
	static Image ConvertToGray(Image inputImage);
};
