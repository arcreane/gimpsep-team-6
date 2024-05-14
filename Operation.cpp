#include "operation.h"
#include <opencv2/opencv.hpp>

using namespace cv;


Image Operation::DilatationOrErosion(Image inputImage, int size, bool isErosion) {
	if (size < 0) {
		size = 0;
	}
	else if (size > 30) {
		size = 30;
	}

	int type = MORPH_ELLIPSE; // Voir si on ajoute un param�tre pour choisir le type
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
		factor = (factor > 10) ? 10 : factor;
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

Image Operation::CannyEdgeDetection(Image inputImage, double lowThreshold, double highThreshold, double kernel) {
	Mat inputMat = inputImage.getImage();

	Mat gray;
	if (inputMat.channels() > 1) {
		cvtColor(inputMat, gray, COLOR_BGR2GRAY);
	}
	else {
		gray = inputMat;
	}

	Mat edges;
	Canny(gray, edges, lowThreshold, highThreshold, kernel);


	return Image(edges);
}

Image Operation::Stitching(Image imageRight, Image imageLeft) {
	Mat inputImageRight = imageRight.getImage();
	Mat inputImageLeft = imageLeft.getImage();

	vector<Mat> inputImages;
	inputImages.push_back(inputImageRight);
	inputImages.push_back(inputImageLeft);

	Stitcher::Mode mode = Stitcher::PANORAMA;
	Ptr<Stitcher> stitcher = Stitcher::create(mode);

	Mat outputMat;
	Stitcher::Status status = stitcher->stitch(inputImages, outputMat);

	// look for errors
	if (status != Stitcher::OK) {
		cout << "Stiching failed.\n";
		return inputImageRight;
	}

	return Image(outputMat);
}
