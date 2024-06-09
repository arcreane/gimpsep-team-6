[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Bnx15ZSC)

# Image and Video Editor with OpenCV

## Overview

This project aims to develop an image and video editor using the OpenCV library in C++. It provides basic graphical user interface functionalities for uploading and saving images and videos, as well as options to perform various editing operations. Parameters for editing are selected via the console interface.

## Installation

### Requirements
- OpenCV

### Setup OpenCV with Visual Studio Community

1. Download the OpenCV library from the official [OpenCV website](https://opencv.org/releases/).
2. Extract the downloaded OpenCV zip file to a convenient location on your system.
3. Create a new environment variable named OPENCV_PATH and set its value to the path where you extracted the OpenCV library.
4. Right-click on the project in Solution Explorer, and select **Properties**.
5. Navigate to **Configuration Properties** > **VC++ Directories**.
6. Add the path to the OpenCV include directory to **Include Directories**.
7. Under **Linker**, add the path to the OpenCV library directory to **Library Directories**.
8. Finally, under **Linker** > **Input**, add `opencv_world490d.lib`.

### Building and Running

1. Clone this repository to your local machine.
2. Open the project in Visual Studio Community.
3. Build the project.
4. Run the project.

## Features

- Basic graphical user interface for image and video upload, and saving.
- Console interface for selecting editing parameters.
- Editing operations included:
  - Dilatation and erosion
  - Resizing
  - Brightness change
  - Stitching (for images only)
  - Edge detection
  - Crop
  - Rotation
  - Change color
  - Convert to gray
  - Add waterwark
  - Image recognition (for images only)

## Libraries Used

- **OpenCV**: Main library for image and video processing.
- **cvui**: Library for creating graphical user interfaces.
