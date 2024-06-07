#pragma once
#include <iostream>
#include "Image.h"
#include "video.h"
#include "faceRecognition.h"

Image* performErosionDilation(Image* inputImage);
Video* performErosionDilationVideo(Video* inputVideo);
Image* performResizing(Image* inputImage);
Video* performResizingVideo(Video* inputVideo);
Image* performBrightnessChange(Image* inputImage);
Video* performBrightnessChangeVideo(Video* inputVideo);
Image* performCannyEdgeDetection(Image* inputImage);
Video* performCannyEdgeDetectionVideo(Video* inputVideo);
Image* performCrop(Image* inputImage);
Video* performCropVideo(Video* inputVideo);
Image* performRotation(Image* inputImage);
Video* performRotationVideo(Video* inputVideo);
Image* performChangeColor(Image* inputImage);
Video* performChangeColorVideo(Video* inputVideo);
Image* performConvertToGray(Image* inputImage);
Video* performConvertToGrayVideo(Video* inputVideo);
Image* performAddWatermark(Image* inputImage);
Video* performAddWatermarkVideo(Video* inputVideo);
Image* performDetection(Image* inputImage);
//Video* performDetectionVideo(Video* inputVideo);
Image* performStitching(Image* inputImage);

vector<FaceRecognizer*> getFaceRecognizers();

Image* processChoice(int choice, Image* inputImage);
Video* processChoiceVideo(int choice, Video* inputVideo);
