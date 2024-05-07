#include <iostream>
#include "image.h"
#include "Operation.h"

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
    char choix;
    cout << "Voulez-vous faire une �rosion (e) ou une dilatation (d) ? ";
    cin >> choix;

    bool isErosion;
    if (choix == 'e' || choix == 'E') {
        isErosion = true;
    }
    else {
        isErosion = false;
    }

    int size;
    cout << "Entrez la taille de l'�rosion/dilatation (entre 0 et 30) : ";
    cin >> size;

    Image outputImage = Operation::DilatationOrErosion(inputImage, size, isErosion);
    outputImage.display();
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
        << "[5] Edge Detection\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Performing DilationOrErosion...\n";
        performErosionDilation(inputImage);
        break;
    case 2:
        cout << "Performing Resizing...\n";
        break;
    case 3:
        cout << "Performing Brightness Change...\n";
        break;
    case 4:
        cout << "Performing Stitching...\n";
        break;
    case 5:
        cout << "Performing Edge Detection...\n";
        performCannyEdgeDetection(inputImage);
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }

    return 0;
}