#pragma once
#include "Operation.h"
#include "video.h"
#include <opencv2/opencv.hpp>

class OperationVideo {
public:
    static Video processVideo(Video inputVideo, std::function<Mat(const Mat&)> processFunc);
    static std::function<Mat(const Mat&)> DilatationOrErosion(int size, bool isErosion);
    static std::function<Mat(const Mat&)> Resizing(float factor, int width, int height);
    static std::function<Mat(const Mat&)> BrightnessChange(float factor, bool isBrightness);
    static std::function<Mat(const Mat&)> CannyEdgeDetection(double lowThreshold, double highThreshold, double kernel);
    static std::function<Mat(const Mat&)> Crop(int ymin, int ymax, int xmin, int xmax);
    static std::function<Mat(const Mat&)> Rotation(double rotationAngle);
    static std::function<Mat(const Mat&)> ChangeColor(int colorVariation);
    static std::function<Mat(const Mat&)> ConvertToGray();
};