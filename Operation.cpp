#include "operation.h"

Image Operation::DilatationOrErosion(Image inputImage, int size, bool isErosion) {
	if (size < 0) {
		size = 0; 
	}
	else if (size > 30) {
		size = 30; 
	}
	
	int type = MORPH_ELLIPSE; // Voir si on ajoute un paramètre pour choisir le type
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

Image Operation::Resizing(Image inputImage, float factor, int width, int height) {
	if (factor <= 0 && (width <= 0 || height <= 0)) {
		return inputImage;
	}

	Mat resizedImage;
	if (factor > 0) {
		resize(inputImage.getImage(), resizedImage, Size(), factor, factor);
	}
	else {
		resize(inputImage.getImage(), resizedImage, Size(width, height));
	}

	return Image(resizedImage);
}

Image Operation::BrightnessChange(Image inputImage, float factor, bool isBrightness) {
	Mat outputMat;
	if (isBrightness) {
		const int minBrightnessFactor = -255;
		const int maxBrightnessFactor = 255;
		int intFactor = static_cast<int>(factor);
		if (intFactor < minBrightnessFactor) {
			intFactor = minBrightnessFactor;
		}
		if (intFactor > maxBrightnessFactor) {
			intFactor = maxBrightnessFactor;
		}

		inputImage.getImage().convertTo(outputMat, -1, 1, intFactor);
	}
	else {
		const int minSaturationFactor = 0.0f;
		const int maxSaturationFactor = 3.0f;
		if (factor < minSaturationFactor) {
			factor = minSaturationFactor;
		}
		if (factor > maxSaturationFactor) {
			factor = maxSaturationFactor;
		}

		inputImage.getImage().convertTo(outputMat, -1, factor, 0);
	}
	return Image(outputMat);
}

//Image Operation::Stitching(Image* images) {}

//Image Operation::CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel) {}

