#pragma once
#include <iostream>
#include "image.h"
#include "video.h"

void performErosionDilation(Image* inputImage);
void performErosionDilationVideo(Video* inputVideo);
void performResizing(Image* inputImage);
//void performResizingVideo(Video* inputVideo);
void performBrightnessChange(Image* inputImage);
//void performBrightnessChangeVideo(Video* inputVideo);
void performCannyEdgeDetection(Image* inputImage);
//void performCannyEdgeDetectionVideo(Video* inputVideo);
void performCrop(Image* inputImage);
//void performCropVideo(Video* inputVideo);
void performRotation(Image* inputImage);
//void performRotationVideo(Video* inputVideo);
void performChangeColor(Image* inputImage);
//void performChangeColorVideo(Video* inputVideo);
void performConvertToGray(Image* inputImage);
//void performConvertToGrayVideo(Video* inputVideo);

void processChoice(int choice, bool isImage, Image* inputImage, Video* inputVideo);