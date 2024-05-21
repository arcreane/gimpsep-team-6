#include <iostream>
#include "image.h"
#include "Operation.h"
#include "video.h"

using namespace std;
using namespace cv;

void performCannyEdgeDetection(Image& inputImage) {
    double lowThreshold, highThreshold;
    cout << "Enter the low threshold: ";
    cin >> lowThreshold;
    cout << "Enter the high threshold: ";
    cin >> highThreshold;

    double kernel;
    cout << "Enter the kernel size: ";
    cin >> kernel;

    Image outputImage = Operation::CannyEdgeDetection(inputImage, lowThreshold, highThreshold, kernel);
    outputImage.display();
}

void performErosionDilation(Image& inputImage) {
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

    Image outputImage = Operation::DilatationOrErosion(inputImage, size, isErosion);
    outputImage.display();

}

void performResizing(Image& inputImage) {
    char choice;
    cout << "Do you want to specify new dimensions (d) or a resizing factor (f)? ";
    cin >> choice;

    if (choice == 'd' || choice == 'D') {
        int width, height;
        cout << "Enter the new dimensions (width height): ";
        cin >> width >> height;

        Image outputImage = Operation::Resizing(inputImage, 0, width, height);
        outputImage.display();
    }
    else if (choice == 'f' || choice == 'F') {
        float factor;
        cout << "Enter the resizing factor (> 0): ";
        cin >> factor;

        Image outputImage = Operation::Resizing(inputImage, factor, 0, 0);
        outputImage.display();
    }
    else {
        cout << "Invalid choice." << endl;
    }


}

void performBrightnessChange(Image& inputImage) {
    char choice;
    cout << "Do you want to perform a brightness change (b) or saturation change (s)? ";
    cin >> choice;
    float factor;

    if (choice == 'b' || choice == 'B') {
        cout << "Enter the brightness factor (between -255 and 255): ";
        cin >> factor;

        Image outputImage = Operation::BrightnessChange(inputImage, factor, true);
        outputImage.display();
    }
    else if (choice == 's' || choice == 'S') {
        cout << "Enter the saturation factor (between 0 and 3): ";
        cin >> factor;

        Image outputImage = Operation::BrightnessChange(inputImage, factor, false);
        outputImage.display();
    }
    else {
        cout << "Invalid choice." << endl;
    }


}

void performCrop(Image& inputImage) {
    int xmin, xmax, ymin, ymax;

    cout << "Enter the value for ymin (min: 0): ";
    cin >> ymin;
    cout << "Enter the value for ymax (max: " << inputImage.getDimensions().height << "): ";
    cin >> ymax;
    cout << "Enter the value for xmin (min: 0): ";
    cin >> xmin;
    cout << "Enter the value for xmax (max: " << inputImage.getDimensions().width << "): ";
    cin >> xmax;

    if (xmin < 0 || xmax > inputImage.getDimensions().width || ymin < 0 || ymax > inputImage.getDimensions().height || xmin >= xmax || ymin >= ymax) {
        cout << "Invalid crop dimensions." << endl;
        return;
    }

    Image outputImage = Operation::Crop(inputImage, ymin, ymax, xmin, xmax);
    outputImage.display();

}

void performRotation(Image& inputImage) {
    double rotationAngle;
    cout << "Enter the rotation angle: ";
    cin >> rotationAngle;

    Image rotatedImage = Operation::Rotation(inputImage, rotationAngle);

    rotatedImage.display();
}

void performChangeColor(Image& inputImage) {
    int colorVariation;
    cout << "Enter the color variation value (between -180 and 180): ";
    cin >> colorVariation;

    Image changedImage = Operation::ChangeColor(inputImage, colorVariation);

    changedImage.display();
}

void performConvertToGray(Image& inputImage) {
    Image grayImage = Operation::ConvertToGray(inputImage);
    grayImage.display();
}

void performStitching() {
    int nbImages;
    cout << "Enter the number of images you want to stitch: ";
    cin >> nbImages;

    vector<Mat> inputImages;
    for (int i = 0; i < nbImages; i++) {
        string imagePath;
        cout << "Enter the path to the input image: ";
        cin >> imagePath;
        Image inputImage(imagePath);
        Mat inputMatrice = inputImage.getImage();
        inputImages.push_back(inputMatrice);
    }

    Image outputImage = Operation::Stitching(inputImages);
    outputImage.display();
}

void performAddWatermark(Image& inputImage) {
    string logoPath;
    cout << "Enter the path to the logo image: ";
    cin >> logoPath;
    Image logo(logoPath);

    double alpha;
    cout << "Enter the alpha (between 0 and 1): ";
    cin >> alpha;

    Image watermarkImage = Operation::AddWatermark(inputImage, logo, alpha);
    watermarkImage.display();
}

int main() {
    string imagePath;
    cout << "Enter the path to the input image: ";
    cin >> imagePath;
    Image inputImage(imagePath);
    inputImage.display();

    int choice;
    cout << "Enter choice of what you want to do:\n"
        << "[1] DilationOrErosion\n"
        << "[2] Resizing\n"
        << "[3] Brightness Change\n"
        << "[4] Stitching\n"
        << "[5] Edge Detection\n"
        << "[6] Crop\n"
        << "[7] Rotation\n"
        << "[8] Change color\n"
        << "[9] Convert to gray\n"
        << "[10] Add a watermark\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Performing DilationOrErosion...\n";
        performErosionDilation(inputImage);
        break;
    case 2:
        cout << "Performing Resizing...\n";
        performResizing(inputImage);
        break;
    case 3:
        cout << "Performing Brightness Change...\n";
        performBrightnessChange(inputImage);
        break;
    case 4:
        cout << "Performing Stitching...\n";
        performStitching();
        break;
    case 5:
        cout << "Performing Edge Detection...\n";
        performCannyEdgeDetection(inputImage);
        break;
    case 6:
        cout << "Performing Crop...\n";
        performCrop(inputImage);
        break;
    case 7:
        cout << "Performing Rotation...\n";
        performRotation(inputImage);
        break;
    case 8:
        cout << "Performing Change color...\n";
        performChangeColor(inputImage);
        break;
    case 9:
        cout << "Performing Convert to gray...\n";
        performConvertToGray(inputImage);
        break;
    case 10:
        cout << "Performing Add a watermark...\n";
        performAddWatermark(inputImage);
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }

    return 0;
}