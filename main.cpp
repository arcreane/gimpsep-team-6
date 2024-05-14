#include <iostream>
#include "process.h"

using namespace std;
using namespace cv;

int main() {     
    char typeChoice;
    bool isImage;
    cout << "Do you want to process an image [i] or a video [v] ?";
    cin >> typeChoice;

    Image* inputImage = nullptr;
    Video* inputVideo = nullptr;

    if (typeChoice == 'i' || typeChoice == 'I') {
        isImage = true;
    }
    else if (typeChoice == 'v' || typeChoice == 'V') {
        isImage = false;
    }
    else {
        cout << "The input is not correct." << endl;
        return 1; // Exit the program if the input is not correct
    }

    try {
        if (isImage) {
            string imagePath;
            imagePath = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/HappyFish.jpg";
            //cout << "Enter the path to the input image: ";
            //cin >> imagePath;
            inputImage = new Image(imagePath); 
            inputImage->display();
        }
        else {
            string videoPath;
            videoPath = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/chaplin.mp4";

            //cout << "Enter the path to the input video: ";
            //cin >> videoPath;
            inputVideo = new Video(videoPath); 
            inputVideo->display();
        }

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
            << "[9] Convert to gray\n";
        cin >> choice;

        processChoice(choice, isImage, inputImage, inputVideo);

        if (inputImage) delete inputImage;
        if (inputVideo) delete inputVideo;
    }
<<<<<<< HEAD
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
=======
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

void performStitching(Image& imageRight, Image& imageLeft) {
    Image outputImage = Operation::Stitching(imageRight, imageLeft);
    outputImage.display();
}

int main() {
    string imagePath = "C:/Users/Lisa/source/repos/ConsoleApplication3/ConsoleApplication3/res/HappyFish.jpg";
    //cout << "Enter the path to the input image: ";
    //getline(cin, imagePath);
    Image inputImage(imagePath);
    inputImage.display();

    // images for stitching
    string imagePathRight = "C:/Users/Lisa/source/repos/ConsoleApplication3/ConsoleApplication3/res/DSC02361_right.JPG";
    Image inputImageRight(imagePathRight);
    string imagePathLeft = "C:/Users/Lisa/source/repos/ConsoleApplication3/ConsoleApplication3/res/DSC02361_left.JPG";
    Image inputImageLeft(imagePathLeft);


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
        performStitching(inputImageRight, inputImageLeft);
        break;
    case 5:
        cout << "Performing Edge Detection...\n";
        performCannyEdgeDetection(inputImage);
        break;
    default:
        cout << "Invalid choice!\n";
        break;
>>>>>>> fonction stitching
    }
    

    return 0;
}