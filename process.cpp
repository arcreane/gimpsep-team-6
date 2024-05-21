#pragma once
#include <iostream>
#include "process.h"
#include "image.h"
#include "Operation.h"
#include "video.h"
#include "operationVideo.h"

using namespace std;
using namespace cv;

void processChoice(int choice, bool isImage, Image* inputImage, Video* inputVideo) {
    switch (choice) {
    case 1:
        cout << "Performing DilationOrErosion...\n";
        if (isImage) {
            performErosionDilation(inputImage);
        }
        else {
            performErosionDilationVideo(inputVideo);
        }
        break;
    case 2:
        cout << "Performing Resizing...\n";
        if (isImage) {
            performResizing(inputImage);
        }
        /*else {
            performResizingVideo(inputVideo);
        }*/
        break;
    case 3:
        cout << "Performing Brightness Change...\n";
        if (isImage) {
            performBrightnessChange(inputImage);
        }
        /*else {
            performBrightnessChangeVideo(inputVideo);
        }*/
        break;
    case 4:
        cout << "Performing Stitching...\n";
        if (isImage) {
            performStitching(inputImage);
        }
        else {
            "Not available for videos";
        }
        break;
    case 5:
        cout << "Performing Edge Detection...\n";
        if (isImage) {
            performCannyEdgeDetection(inputImage);
        }
        /*else {
            performCannyEdgeDetectionVideo(inputVideo);
        }*/
        break;
    case 6:
        cout << "Performing Crop...\n";
        if (isImage) {
            performCrop(inputImage);
        }
        /*else {
            performCropVideo(inputVideo);
        }*/
        break;
    case 7:
        cout << "Performing Rotation...\n";
        if (isImage) {
            performRotation(inputImage);
        }
        /*else {
            performRotationVideo(inputVideo);
        }*/
        break;
    case 8:
        cout << "Performing Change color...\n";
        if (isImage) {
            performChangeColor(inputImage);
        }
        /*else {
            performChangeColorVideo(inputVideo);
        }*/
        break;
    case 9:
        cout << "Performing Convert to gray...\n";
        if (isImage) {
            performConvertToGray(inputImage);
        }
        /*else {
            performConvertToGrayVideo(inputVideo);
        }*/
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }
}

void performCannyEdgeDetection(Image* inputImage) {
    double lowThreshold, highThreshold;
    cout << "Enter the low threshold: ";
    cin >> lowThreshold;
    cout << "Enter the high threshold: ";
    cin >> highThreshold;

    double kernel;
    cout << "Enter the kernel size: ";
    cin >> kernel;

    Image outputImage = Operation::CannyEdgeDetection(*inputImage, lowThreshold, highThreshold, kernel);
    outputImage.display();
}

void performErosionDilation(Image* inputImage) {
    char choice;
    cout << "Do you want to perform erosion (e) or dilation (d)? ";
    cin >> choice;

    bool isErosion;
    if (choice == 'e' || choice == 'E') {
        isErosion = true;
    }
    else {
        isErosion = false;
    }

    int size;
    cout << "Enter the size for erosion/dilation (between 0 and 30): ";
    cin >> size;

    Image outputImage = Operation::DilatationOrErosion(*inputImage, size, isErosion);
    outputImage.display();

}

void performErosionDilationVideo(Video* inputVideo) {
    char choice;
    cout << "Do you want to perform erosion (e) or dilation (d)? ";
    cin >> choice;

    bool isErosion;
    if (choice == 'e' || choice == 'E') {
        isErosion = true;
    }
    else {
        isErosion = false;
    }

    int size;
    cout << "Enter the size for erosion/dilation (between 0 and 30): ";
    cin >> size;

    Video outputVideo = OperationVideo::processVideo(*inputVideo, OperationVideo::DilatationOrErosion(size, isErosion));
    outputVideo.display();

}

void performResizing(Image* inputImage) {
    char choice;
    cout << "Do you want to specify new dimensions (d) or a resizing factor (f)? ";
    cin >> choice;

    if (choice == 'd' || choice == 'D') {
        int width, height;
        cout << "Enter the new dimensions (width height): ";
        cin >> width >> height;

        Image outputImage = Operation::Resizing(*inputImage, 0, width, height);
        outputImage.display();
    }
    else if (choice == 'f' || choice == 'F') {
        float factor;
        cout << "Enter the resizing factor (> 0): ";
        cin >> factor;

        Image outputImage = Operation::Resizing(*inputImage, factor, 0, 0);
        outputImage.display();
    }
    else {
        cout << "Invalid choice." << endl;
    }


}

void performBrightnessChange(Image* inputImage) {
    char choice;
    cout << "Do you want to perform a brightness change (b) or saturation change (s)? ";
    cin >> choice;
    float factor;

    if (choice == 'b' || choice == 'B') {
        cout << "Enter the brightness factor (between -255 and 255): ";
        cin >> factor;

        Image outputImage = Operation::BrightnessChange(*inputImage, factor, true);
        outputImage.display();
    }
    else if (choice == 's' || choice == 'S') {
        cout << "Enter the saturation factor (between 0 and 3): ";
        cin >> factor;

        Image outputImage = Operation::BrightnessChange(*inputImage, factor, false);
        outputImage.display();
    }
    else {
        cout << "Invalid choice." << endl;
    }


}

void performCrop(Image* inputImage) {
    int xmin, xmax, ymin, ymax;

    cout << "Enter the value for ymin (min: 0): ";
    cin >> ymin;
    cout << "Enter the value for ymax (max: " << inputImage->getDimensions().height << "): ";
    cin >> ymax;
    cout << "Enter the value for xmin (min: 0): ";
    cin >> xmin;
    cout << "Enter the value for xmax (max: " << inputImage->getDimensions().width << "): ";
    cin >> xmax;

    if (xmin < 0 || xmax > inputImage->getDimensions().width || ymin < 0 || ymax > inputImage->getDimensions().height || xmin >= xmax || ymin >= ymax) {
        cout << "Invalid crop dimensions." << endl;
        return;
    }

    Image outputImage = Operation::Crop(*inputImage, ymin, ymax, xmin, xmax);
    outputImage.display();

}

void performRotation(Image* inputImage) {
    double rotationAngle;
    cout << "Enter the rotation angle: ";
    cin >> rotationAngle;

    Image rotatedImage = Operation::Rotation(*inputImage, rotationAngle);

    rotatedImage.display();
}

void performChangeColor(Image* inputImage) {
    int colorVariation;
    cout << "Enter the color variation value (between -180 and 180): ";
    cin >> colorVariation;

    Image changedImage = Operation::ChangeColor(*inputImage, colorVariation);

    changedImage.display();
}

void performConvertToGray(Image* inputImage) {
    Image grayImage = Operation::ConvertToGray(*inputImage);
    grayImage.display();
}

void performStitching(Image* inputImage) {
    vector<Mat> inputImages;

    Mat firstMat = inputImage->getImage();
    inputImages.push_back(firstMat);

    char addMore;
    do {
        string filePath;
        cout << "Enter the path to the next input image (or 'n' to stop): ";
        cin >> filePath;

        if (filePath == "n") {
            break;
        }

        Mat image = imread(filePath);
        if (image.empty()) {
            cout << "Could not open or find the image: " << filePath << endl;
        }
        else {
            inputImages.push_back(image);
        }

    } while (true);

    if (inputImages.size() < 2) {
        cout << "Need at least two images to perform stitching." << endl;
        return;
    }

    Image stitchedImage = Operation::Stitching(inputImages);
    stitchedImage.display();
}

//Add stitching
