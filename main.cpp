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
            //imagePath = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/HappyFish.jpg";
            imagePath = "C:/Users/marie/Pictures/image_c1.jpg";
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
            << "[4] Stitching (not for videos)\n"
            << "[5] Edge Detection\n"
            << "[6] Crop\n"
            << "[7] Rotation\n"
            << "[8] Change color\n"
            << "[9] Convert to gray\n"
            << "[10] Add a watermark\n";
        cin >> choice;

        processChoice(choice, isImage, inputImage, inputVideo);

        if (inputImage) delete inputImage;
        if (inputVideo) delete inputVideo;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    

    return 0;
}