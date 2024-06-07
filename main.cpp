#include <iostream>
#include "process.h"
#include "Operation.h"

#define CVUI_IMPLEMENTATION
#include "cvui.h"

using namespace std;
using namespace cv;
using namespace cvui;

#define WINDOW_NAME	"CVUI"


int main() {
    init(WINDOW_NAME);

    Mat frame = Mat(800, 1000, CV_8UC3);

    bool isImage = true;
    bool display = false;
    int choice = -1;

    Image* inputImage = nullptr;
    Image* outputImage = nullptr;
    Video* inputVideo = nullptr;
    Video* outputVideo = nullptr;

    char savePath[100] = "output.jpg"; 

    while (true) {
        frame = Scalar(49, 52, 49);

        text(frame, 50, 30, "Select Operation:");
        if (button(frame, 50, 60, "1. Dilation or Erosion")) {
            choice = 1;
        }
        if (button(frame, 50, 90, "2. Resizing")) {
            choice = 2;
        }
        if (button(frame, 50, 120, "3. Brightness Change")) {
            choice = 3;
        }
        if (button(frame, 50, 150, "4. Stitching")) {
            choice = 4;
        }
        if (button(frame, 50, 180, "5. Edge Detection")) {
            choice = 5;
        }
        if (button(frame, 50, 210, "6. Crop")) {
            choice = 6;
        }
        if (button(frame, 50, 240, "7. Rotation")) {
            choice = 7;
        }
        if (button(frame, 50, 270, "8. Change Color")) {
            choice = 8;
        }
        if (button(frame, 50, 300, "9. Convert to Gray")) {
            choice = 9;
        }
        if (button(frame, 50, 330, "10. Add Watermark")) {
            choice = 10;
        }
        if (button(frame, 50, 360, "11. Image Recognition")) {
            choice = 11;
        }

        if (button(frame, 150, 470, "Upload Image")) {
            String imagePath;
            //cout << "Path to image" << endl;
            //cin >> imagePath;
            //inputImage = new Image(imagePath);
            inputImage = new Image("C:/Users/lenaf/OneDrive/Pictures/icons/face.jpg");
        }

        if (button(frame, 300, 470, "Upload Video")) {
            String imagePath;
            cout << "Path to video" << endl;
            cin >> imagePath;
            inputVideo = new Video(imagePath);
            isImage = false;
            text(frame, 150, 500, "Video Uploaded");
        }

        if (inputImage != nullptr && isImage) {
            Mat imgMat = inputImage->getImage();
            imgMat.copyTo(frame(Rect(400, 50, imgMat.cols, imgMat.rows)));
        }

        if (choice != -1 && (inputImage != nullptr || inputVideo != nullptr)) {
            if (isImage) {
                outputImage = processChoice(choice, inputImage);
            }
            else {
                processChoiceVideo(choice, inputVideo);
            }
            display = true;
            choice = -1;
        }

        if (outputImage != nullptr) {
            Mat imgMat = outputImage->getImage();
            if (imgMat.cols <= frame.cols - 400 && imgMat.rows <= frame.rows - 50) {
                if (imgMat.channels() == 1) {
                    cv::cvtColor(imgMat, imgMat, cv::COLOR_GRAY2BGR);
                }
                imgMat.copyTo(frame(Rect(400, 50, imgMat.cols, imgMat.rows)));
            }
            else if (display == true) {
                outputImage->display();
                display = false;
            }

            if (button(frame, 50, 470, "Save image")) {
                String imagePath;
                cout << "Path to image" << endl;
                cin >> imagePath;

                String imageName;
                cout << "Name of image" << endl;
                cin >> imageName;
                outputImage->save(imagePath + '\\' + imageName);
            }
        }

        if (outputVideo != nullptr) {
            if (display == true) {
                outputVideo->display();
                display = false;
            }

            if (button(frame, 50, 470, "Save video")) {
                String videoPath;
                cout << "Path to video" << endl;
                cin >> videoPath;

                String videoName;
                cout << "Name of video" << endl;
                cin >> videoName;
                outputImage->save(videoPath + '\\' + videoName);
            }
        }

        update();
        cv::imshow(WINDOW_NAME, frame);

        if (waitKey(20) == 27) {
            break;
        }
    }

    delete inputImage;
    delete inputVideo;

    return 0;
}