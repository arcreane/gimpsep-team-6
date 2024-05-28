#pragma once
#include "Operation.h"
#include "video.h"
#include <opencv2/opencv.hpp>

class OperationVideo {
public:
    static Video processVideo(Video inputVideo, std::function<Mat(const Mat&)> processFunc);
    static std::function<Mat(const Mat&)> DilatationOrErosion(int size, bool isErosion);
    //static Video Resizing(Video inputVideo, float factor, int width, int height);
    //static Video BrightnessChange(Video inputVideo, float factor, bool isBrightness);
    //static Video CannyEdgeDetection(Video inputVideo, double lowThreshold, double highThreshold, double kernel);
    //static Video Crop(Video inputVideo, int ymin, int ymax, int xmin, int xmax);
    //static Video Rotation(Video inputVideo, double rotationAngle);
    //static Video ChangeColor(Video inputVideo, int colorVariation);
    //static Video ConvertToGray(Video inputVideo);
    static std::function<Mat(const Mat&)> AddWatermark(Image logo, double alpha);
};