#pragma once
#include "operationVideo.h"
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>

using namespace cv;

Video OperationVideo::processVideo(Video inputVideo, std::function<Mat(const Mat&)> processFunc) {
    std::vector<Mat> frames = inputVideo.getFrames();
    std::vector<Mat> processedFrames(frames.size());

    std::vector<std::thread> threads;
    std::atomic<int> currentFrameIndex(0);

    auto worker = [&]() {
        while (true) {
            int frameIndex = currentFrameIndex.fetch_add(1);
            if (frameIndex >= frames.size()) {
                break;
            }
            processedFrames[frameIndex] = processFunc(frames[frameIndex]);
        }
        };

    int numThreads = std::thread::hardware_concurrency();
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(worker);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return Video(processedFrames, inputVideo.getFPS());
}


std::function<Mat(const Mat&)> OperationVideo::DilatationOrErosion(int size, bool isErosion) {
    return [size, isErosion](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::DilatationOrErosion(img, size, isErosion);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::Resizing(float factor, int width, int height) {
    return [factor, width, height](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::Resizing(img, factor, width, height);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::BrightnessChange(float factor, bool isBrightness) {
    return [factor, isBrightness](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::BrightnessChange(img, factor, isBrightness);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::CannyEdgeDetection(double lowThreshold, double highThreshold, double kernel) {
    return [lowThreshold, highThreshold, kernel](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::CannyEdgeDetection(img, lowThreshold, highThreshold, kernel);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::Crop(int ymin, int ymax, int xmin, int xmax) {
    return [ymin, ymax, xmin, xmax](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::Crop(img, ymin, ymax, xmin, xmax);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::Rotation(double rotationAngle) {
    return [rotationAngle](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::Rotation(img, rotationAngle);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::ChangeColor(int colorVariation) {
    return [colorVariation](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::ChangeColor(img, colorVariation);
        return processedImg.getImage();
        };
}

std::function<Mat(const Mat&)> OperationVideo::ConvertToGray() {
    return [](const Mat& frame) -> Mat {
        Image img(frame);
        Image processedImg = Operation::ConvertToGray(img);
        return processedImg.getImage();
        };
}