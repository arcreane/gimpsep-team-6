#include "operation.h"


Image Operation::DilatationOrErosion(Image inputImage, int size, bool isErosion) {
	if (size < 0) {
		size = 0; 
	}
	else if (size > 30) {
		size = 30; 
	}
	
	int type = MORPH_ELLIPSE;
	Mat outputMat;
	Mat element = getStructuringElement(type, Size(2 * size + 1, 2 * size + 1), Point(size, size));
	if (isErosion) {
		erode(inputImage.getImage(), outputMat, element);
	}
	else {
		dilate(inputImage.getImage(), outputMat, element);
	}
	return Image(outputMat);
}

Image Operation::Resizing(Image inputImage, int factor) {}

Image Operation::BrightnessChange(Image inputImage, int factor) {}

Image Operation::Stitching(Image* images) {}

Image Operation::CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel) {}

