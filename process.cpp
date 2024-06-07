#pragma once
#include <iostream>
#include "process.h"
#include "image.h"
#include "Operation.h"
#include "video.h"
#include "operationVideo.h"
#include "faceRecognition.h"

using namespace std;
using namespace cv;

Image* processChoice(int choice, Image* inputImage) {
    Image* outputImage = nullptr;
    switch (choice) {
    case 1:
        cout << "Performing DilationOrErosion...\n";
        outputImage = performErosionDilation(inputImage);
        break;
    case 2:
        cout << "Performing Resizing...\n";
        outputImage = performResizing(inputImage);
        break;
    case 3:
        cout << "Performing Brightness Change...\n";
        outputImage = performBrightnessChange(inputImage);
        break;
    case 4:
        cout << "Performing Stitching...\n";
        outputImage = performStitching(inputImage);
        break;
    case 5:
        cout << "Performing Edge Detection...\n";
        outputImage = performCannyEdgeDetection(inputImage);
        break;
    case 6:
        cout << "Performing Crop...\n";
        outputImage = performCrop(inputImage);
        break;
    case 7:
        cout << "Performing Rotation...\n";
        outputImage = performRotation(inputImage);
        break;
    case 8:
        cout << "Performing Change color...\n";
        outputImage = performChangeColor(inputImage);
        break;
    case 9:
        cout << "Performing Convert to gray...\n";
        outputImage = performConvertToGray(inputImage);
        break;
    case 10:
        cout << "Performing Add a watermark...\n";
        outputImage = performAddWatermark(inputImage);
        break;
    case 11:
        cout << "Performing image recognition...\n";
        outputImage = performDetection(inputImage);
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }
    return outputImage;
}

Video* processChoiceVideo(int choice, Video* inputVideo) {
    Video* outputVideo = nullptr;
    switch (choice) {
    case 1:
        cout << "Performing DilationOrErosion...\n";
        outputVideo = performErosionDilationVideo(inputVideo);
        break;
    case 2:
        cout << "Performing Resizing...\n";
        outputVideo = performResizingVideo(inputVideo);
        break;
    case 3:
        cout << "Performing Brightness Change...\n";
        outputVideo = performBrightnessChangeVideo(inputVideo);
        break;
    case 4:
        cout << "Stitching on videos not available.";
        break;
    case 5:
        cout << "Performing Edge Detection...\n";
        outputVideo = performCannyEdgeDetectionVideo(inputVideo);
        break;
    case 6:
        cout << "Performing Crop...\n";
        outputVideo = performCropVideo(inputVideo);
        break;
    case 7:
        cout << "Performing Rotation...\n";
        outputVideo = performRotationVideo(inputVideo);
        break;
    case 8:
        cout << "Performing Change color...\n";
        outputVideo = performChangeColorVideo(inputVideo);
        break;
    case 9:
        cout << "Performing Convert to gray...\n";
        outputVideo = performConvertToGrayVideo(inputVideo);
        break;
    case 10:
        cout << "Performing Add a watermark...\n";
        outputVideo = performAddWatermarkVideo(inputVideo);
        break;
    case 11:
        cout << "Performing image recognition...\n";
        //outputVideo = performDetectionVideo(inputVideo);
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }
    return outputVideo;
}


Image* performCannyEdgeDetection(Image* inputImage) {
    double lowThreshold, highThreshold;
    cout << "Enter the low threshold: ";
    cin >> lowThreshold;
    cout << "Enter the high threshold: ";
    cin >> highThreshold;

    double kernel;
    cout << "Enter the kernel size: ";
    cin >> kernel;

    Image* outputImage = new Image(Operation::CannyEdgeDetection(*inputImage, lowThreshold, highThreshold, kernel));
    return outputImage;
}

Video* performCannyEdgeDetectionVideo(Video* inputVideo) {
    double lowThreshold, highThreshold;
    cout << "Enter the low threshold: ";
    cin >> lowThreshold;
    cout << "Enter the high threshold: ";
    cin >> highThreshold;

    double kernel;
    cout << "Enter the kernel size: ";
    cin >> kernel;

    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::CannyEdgeDetection(lowThreshold, highThreshold, kernel)));
    return outputVideo;
}

Image* performErosionDilation(Image* inputImage) {
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

    Image* outputImage = new Image(Operation::DilatationOrErosion(*inputImage, size, isErosion));
    return outputImage;
}

Video* performErosionDilationVideo(Video* inputVideo) {
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

    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::DilatationOrErosion(size, isErosion)));
    return outputVideo;

}

Image* performResizing(Image* inputImage) {
    char choice;
    cout << "Do you want to specify new dimensions (d) or a resizing factor (f)? ";
    cin >> choice;

    if (choice == 'd' || choice == 'D') {
        int width, height;
        cout << "Enter the new dimensions (width height): ";
        cin >> width >> height;

        Image* outputImage = new Image(Operation::Resizing(*inputImage, 0, width, height));
        return outputImage;
    }
    else if (choice == 'f' || choice == 'F') {
        float factor;
        cout << "Enter the resizing factor (> 0): ";
        cin >> factor;

        Image* outputImage = new Image(Operation::Resizing(*inputImage, factor, 0, 0));
        return outputImage;
    }
    else {
        cout << "Invalid choice." << endl;
        return nullptr;
    }
}

Video* performResizingVideo(Video* inputVideo) {
    char choice;
    cout << "Do you want to specify new dimensions (d) or a resizing factor (f)? ";
    cin >> choice;

    if (choice == 'd' || choice == 'D') {
        int width, height;
        cout << "Enter the new dimensions (width height): ";
        cin >> width >> height;

        Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::Resizing(0, width, height)));
        return outputVideo;
    }
    else if (choice == 'f' || choice == 'F') {
        float factor;
        cout << "Enter the resizing factor (> 0): ";
        cin >> factor;

        Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::Resizing(factor, 0, 0)));
        return outputVideo;
    }
    else {
        cout << "Invalid choice." << endl;
        return nullptr;
    }


}

Image* performBrightnessChange(Image* inputImage) {
    char choice;
    cout << "Do you want to perform a brightness change (b) or saturation change (s)? ";
    cin >> choice;
    float factor;

    if (choice == 'b' || choice == 'B') {
        cout << "Enter the brightness factor (between -255 and 255): ";
        cin >> factor;

        Image* outputImage = new Image(Operation::BrightnessChange(*inputImage, factor, true));
        return outputImage;
    }
    else if (choice == 's' || choice == 'S') {
        cout << "Enter the saturation factor (between 0 and 3): ";
        cin >> factor;

        Image* outputImage = new Image(Operation::BrightnessChange(*inputImage, factor, false));
        return outputImage;
    }
    else {
        cout << "Invalid choice." << endl;
        return nullptr;
    }
}

Video* performBrightnessChangeVideo(Video* inputVideo) {
    char choice;
    cout << "Do you want to perform a brightness change (b) or saturation change (s)? ";
    cin >> choice;
    float factor;

    if (choice == 'b' || choice == 'B') {
        cout << "Enter the brightness factor (between -255 and 255): ";
        cin >> factor;

        Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::BrightnessChange(factor, true)));
        return outputVideo;
    }
    else if (choice == 's' || choice == 'S') {
        cout << "Enter the saturation factor (between 0 and 3): ";
        cin >> factor;

        Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::BrightnessChange(factor, false)));
        return outputVideo;
    }
    else {
        cout << "Invalid choice." << endl;
        return nullptr;
    }
}

Image* performCrop(Image* inputImage) {
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
        return nullptr;
    }

    Image* outputImage = new Image(Operation::Crop(*inputImage, ymin, ymax, xmin, xmax));
    return outputImage;
}

Video* performCropVideo(Video* inputVideo) {
    int xmin, xmax, ymin, ymax;

    cout << "Enter the value for ymin (min: 0): ";
    cin >> ymin;
    cout << "Enter the value for ymax (max: " << inputVideo->getDimensions().height << "): ";
    cin >> ymax;
    cout << "Enter the value for xmin (min: 0): ";
    cin >> xmin;
    cout << "Enter the value for xmax (max: " << inputVideo->getDimensions().width << "): ";
    cin >> xmax;

    if (xmin < 0 || xmax > inputVideo->getDimensions().width || ymin < 0 || ymax > inputVideo->getDimensions().height || xmin >= xmax || ymin >= ymax) {
        cout << "Invalid crop dimensions." << endl;
        return nullptr;
    }

    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::Crop(ymin, ymax, xmin, xmax)));
    return outputVideo;

}

Image* performRotation(Image* inputImage) {
    double rotationAngle;
    cout << "Enter the rotation angle: ";
    cin >> rotationAngle;

    Image* rotatedImage = new Image(Operation::Rotation(*inputImage, rotationAngle));

    return rotatedImage;
}

Video* performRotationVideo(Video* inputVideo) {
    double rotationAngle;
    cout << "Enter the rotation angle: ";
    cin >> rotationAngle;

    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::Rotation(rotationAngle)));
    return outputVideo;
}

Image* performChangeColor(Image* inputImage) {
    int colorVariation;
    cout << "Enter the color variation value (between -180 and 180): ";
    cin >> colorVariation;

    Image* changedImage = new Image(Operation::ChangeColor(*inputImage, colorVariation));

    return changedImage;
}

//A tester sur une vidéo colorée!!
Video* performChangeColorVideo(Video* inputVideo) {
    int colorVariation;
    cout << "Enter the color variation value (between -180 and 180): ";
    cin >> colorVariation;

    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::ChangeColor(colorVariation)));
    return outputVideo;
}

Image* performConvertToGray(Image* inputImage) {
    Image* grayImage = new Image(Operation::ConvertToGray(*inputImage));
    return grayImage;
}

//A tester sur une vidéo colorée!!
Video* performConvertToGrayVideo(Video* inputVideo) {
    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::ConvertToGray()));
    return outputVideo;
}

Image* performStitching(Image* inputImage) {
    vector<Mat> inputImages;

    Mat firstMat = inputImage->getImage();
    inputImages.push_back(firstMat);

    char addMore = 0;
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
        return nullptr;
    }

    Image* stitchedImage = new Image(Operation::Stitching(inputImages));
    return stitchedImage;
}

Image* performAddWatermark(Image* inputImage) {
    string logoPath;
    cout << "Enter the path to the logo image: ";
    cin >> logoPath;
    Image logo(logoPath);

    double alpha;
    cout << "Enter the alpha (between 0 and 1): ";
    cin >> alpha;

    Image* watermarkImage = new Image(Operation::AddWatermark(*inputImage, logo, alpha));
    return watermarkImage;
}

Video* performAddWatermarkVideo(Video* inputVideo) {
    string logoPath;
    cout << "Enter the path to the logo image: ";
    cin >> logoPath;
    Image logo(logoPath);

    double alpha;
    cout << "Enter the alpha (between 0 and 1): ";
    cin >> alpha;

    Video* outputVideo = new Video(OperationVideo::processVideo(*inputVideo, OperationVideo::AddWatermark(logo, alpha)));
    return outputVideo;
}

Image* performDetection(Image* inputImage) {
    Mat image = inputImage->getImage();
    vector<FaceRecognizer*> faceRecognizers = getFaceRecognizers();

    for (auto& faceRecognizer : faceRecognizers) {
        vector<Rect> detections = faceRecognizer->detectFaces(image);

        for (const auto& detection : detections) {
            rectangle(image, detection, Scalar(255, 0, 0), 2);
        }
    }

    Image* outputImage = new Image(image);
    return outputImage;
}

vector<FaceRecognizer*> getFaceRecognizers() {
    int choice;
    cout << "Enter choice of what you want to detect:\n"
        << "[1] Profile face\n"
        << "[2] Smile\n"
        << "[3] Cat profile face\n"
        << "[4] Russian car plate\n"
        << "[5] Parts of face\n";
    cin >> choice;

    vector<FaceRecognizer*> faceRecognizers;

    string haarPath;

    char* buf = nullptr;
    size_t sz = 0;
    if (_dupenv_s(&buf, &sz, "HAAR_PATH") == 0 && buf != nullptr)
    {
        printf("EnvVarName = %s\n", buf);
        haarPath = buf;
        free(buf);
    }

    switch (choice) {
    case 1:
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_frontalface_alt.xml"));
        break;
    case 2:
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_smile.xml"));
        break;
    case 3:
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_frontalcatface.xml"));
        break;
    case 4:
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_russian_plate_number.xml"));
        break;
    case 5:
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_frontalface_alt.xml"));
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_smile.xml"));
        faceRecognizers.push_back(new FaceRecognizer(haarPath + "haarcascade_eye.xml"));
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }
    
    return faceRecognizers;
}
