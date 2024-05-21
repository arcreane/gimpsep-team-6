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