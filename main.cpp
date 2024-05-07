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
    cout << "Voulez-vous faire une érosion (e) ou une dilatation (d) ? ";
    cin >> choix;

    bool isErosion;
    if (choix == 'e' || choix == 'E') {
        isErosion = true;
    }
    else {
        isErosion = false;
    }

    int size;
    cout << "Entrez la taille de l'érosion/dilatation (entre 0 et 30) : ";
    cin >> size;

    Image outputImage = Operation::DilatationOrErosion(inputImage, size, isErosion);
    outputImage.display();
}

void performResizing(Image& inputImage) {
    char choix;
    cout << "Voulez-vous spécifier les nouvelles dimensions (d) ou un facteur de redimensionnement (f) ? ";
    cin >> choix;

    if (choix == 'd' || choix == 'D') {
        int width, height;
        cout << "Entrez les nouvelles dimensions (largeur hauteur) : ";
        cin >> width >> height;

        Image outputImage = Operation::Resizing(inputImage, 0, width, height);
        outputImage.display();
    }
    else if (choix == 'f' || choix == 'F') {
        float factor;
        cout << "Entrez le facteur de redimensionnement (> 0) : ";
        cin >> factor;

        Image outputImage = Operation::Resizing(inputImage, factor, 0, 0);
        outputImage.display();
    }
    else {
        cout << "Choix invalide." << endl;
    }

}

void performBrightnessChange(Image& inputImage) {
    char choix;
    cout << "Voulez-vous effectuer un changement de luminosité (b) ou de saturation (s) ? ";
    cin >> choix;
    float factor;

    if (choix == 'b' || choix == 'B') {
        cout << "Entrez le facteur de luminosité (entre -255 et 255): ";
        cin >> factor;

        Image outputImage = Operation::BrightnessChange(inputImage, factor, true);
        outputImage.display();
    }
    else if (choix == 's' || choix == 'S') {
        cout << "Entrez le facteur de saturation (entre 0 et 3) : ";
        cin >> factor;

        Image outputImage = Operation::BrightnessChange(inputImage, factor, false);
        outputImage.display();
    }
    else {
        cout << "Choix invalide." << endl;
    }

}

int main() {
    string imagePath = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/HappyFish.jpg";
    //cout << "Enter the path to the input image: ";
    //getline(cin, imagePath);
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
        performResizing(inputImage);
        break;
    case 3:
        cout << "Performing Brightness Change...\n";
        performBrightnessChange(inputImage);
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