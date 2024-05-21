#pragma once
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
		const float minSaturationFactor = 0.0f;
		const float maxSaturationFactor = 3.0f;
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

Image Operation::Crop(Image inputImage, int ymin, int ymax, int xmin, int xmax) {
	Size imgSize = inputImage.getDimensions();

	ymin = max(0, ymin);
	ymax = min(imgSize.height, ymax);
	xmin = max(0, xmin);
	xmax = min(imgSize.width, xmax);

	if (ymin >= ymax || xmin >= xmax) {
		cerr << "Invalid crop dimensions" << endl;
		return Image(inputImage.getImage());
	}

	Mat croppedImage = inputImage.getImage()(Range(ymin, ymax), Range(xmin, xmax));
	return Image(croppedImage);
}

Image Operation::Rotation(Image inputImage, double rotationAngle) {
	Mat source = inputImage.getImage();
	Mat M, result;

	Point2f center(source.cols / 2.0, source.rows / 2.0);
	double scale = 1.0;

	M = getRotationMatrix2D(center, rotationAngle, scale);

	warpAffine(source, result, M, source.size());

	return Image(result);
}

Image Operation::ChangeColor(Image inputImage, int colorVariation) {
	Mat source = inputImage.getImage();
	Mat result;

	cvtColor(source, result, COLOR_BGR2HSV);
	vector<Mat> channels;
	split(result, channels);
	channels[0] += colorVariation;
	merge(channels, result);
	cvtColor(result, result, COLOR_HSV2BGR);
	return Image(result);
}

Image Operation::ConvertToGray(Image inputImage) {
	Mat source = inputImage.getImage();
	Mat result;

	cvtColor(source, result, COLOR_BGR2GRAY);

	return Image(result);
}

Image Operation::Stitching(vector<Mat> inputImages) {
	Stitcher::Mode mode = Stitcher::PANORAMA;
	Ptr<Stitcher> stitcher = Stitcher::create(mode);

	Mat outputMat;
	Stitcher::Status status = stitcher->stitch(inputImages, outputMat);

	// look for errors
	if (status != Stitcher::OK) {
		cout << "Stiching failed.\n";
	}

	return Image(outputMat);
}
