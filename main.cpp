#include <iostream>
#include "process.h"

#define CVUI_IMPLEMENTATION
#include "cvui.h"

using namespace std;
using namespace cv;

#define WINDOW_NAME	"CVUI"

int main() {
	bool checked = false;
	bool checked2 = true;
	int count = 0;
	double trackbarValue = 0.0;

	// Init cvui and tell it to create a OpenCV window, i.e. cv::namedWindow(WINDOW_NAME).
	cvui::init(WINDOW_NAME);

	double scaling = 1.0;
	double currentScaling = -1;
	cv::Mat frame;

	while (true) {
		if (scaling != currentScaling) {
			frame = cv::Mat(std::lround(scaling * 300), std::lround(scaling * 600), CV_8UC3);
			currentScaling = scaling;
		}

		// Fill the frame with a nice color
		frame = cv::Scalar(49, 52, 49);

		// Show some pieces of text.
		cvui::text(frame, std::lround(scaling * 50), std::lround(scaling * 30), "Hey there!", scaling * cvui::DEFAULT_FONT_SCALE);

		// Show everything on the screen
		cv::imshow(WINDOW_NAME, frame);

		// Check if ESC key was pressed
		if (cv::waitKey(20) == 27) {
			break;
		}
	}

    //char typeChoice;
    //bool isImage;
    //cout << "Do you want to process an image [i] or a video [v] ?";
    //cin >> typeChoice;

    //Image* inputImage = nullptr;
    //Video* inputVideo = nullptr;

    //if (typeChoice == 'i' || typeChoice == 'I') {
    //    isImage = true;
    //}
    //else if (typeChoice == 'v' || typeChoice == 'V') {
    //    isImage = false;
    //}
    //else {
    //    cout << "The input is not correct." << endl;
    //    return 1; // Exit the program if the input is not correct
    //}

    //try {
    //    if (isImage) {
    //        string imagePath;
    //        imagePath = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/HappyFish.jpg";
    //        //imagePath = "C:/Users/marie/Pictures/image_c1.jpg";
    //        //cout << "Enter the path to the input image: ";
    //        //cin >> imagePath;
    //        inputImage = new Image(imagePath);
    //        inputImage->display();
    //    }
    //    else {
    //        string videoPath;
    //        videoPath = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/chaplin.mp4";

    //        //cout << "Enter the path to the input video: ";
    //        //cin >> videoPath;
    //        inputVideo = new Video(videoPath);
    //        inputVideo->display();
    //    }

    //    int choice;
    //    cout << "Enter choice of what you want to do:\n"
    //        << "[1] DilationOrErosion\n"
    //        << "[2] Resizing\n"
    //        << "[3] Brightness Change\n"
    //        << "[4] Stitching (not for videos)\n"
    //        << "[5] Edge Detection\n"
    //        << "[6] Crop\n"
    //        << "[7] Rotation\n"
    //        << "[8] Change color\n"
    //        << "[9] Convert to gray\n"
    //        << "[10] Add a watermark\n"
    //        << "[11] Image recognition\n";
    //    cin >> choice;

    //    processChoice(choice, isImage, inputImage, inputVideo);

    //    if (inputImage) delete inputImage;
    //    if (inputVideo) delete inputVideo;
    //}
    //catch (const exception& e) {
    //    cerr << "Error: " << e.what() << endl;
    //    return 1;
    //}
    return 0;
}
