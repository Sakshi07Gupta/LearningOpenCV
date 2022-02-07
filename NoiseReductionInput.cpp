#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;
int main() {
    // Prepare new mat container 
    Mat loadedPictureHere;
    //imread will read the image from file
    loadedPictureHere = imread("E:\\OPENCVr\\opencv\\Assignment2\\Assignment2\\Image2.jpg");

    Mat processedPicture;
    loadedPictureHere.copyTo(processedPicture);
   
       //  blur(loadedPictureHere, processedPicture, Size(5, 5));
    GaussianBlur(loadedPictureHere, processedPicture, Size(17,17), 0, 0);
    medianBlur(loadedPictureHere, processedPicture, 5);
    namedWindow("Step 2", WINDOW_AUTOSIZE);// Create a window for display.
    imshow("Step 2", processedPicture);   // Display loaded image 
    imwrite("Image3.jpg", processedPicture);

    waitKey(0);
    return 0;
}
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const int max_value_H = 179;
const int max_value = 255;

int main()
{
    // string image_path1 = "/home/nicolai/computerVision/images_1/images/BabyFood/BabyFood-Test6.JPG";
     //string image_path2 = "/home/nicolai/computerVision/images_1/images/redHats.jpg";
    // string image_path3 = "/home/nicolai/computerVision/images_1/images/redHatSimple.jpg";
    string path = "E:\\OPENCVr\\opencv\\Assignment2\\Assignment2\\Image3.jpg";
    Mat image1 = imread(path, IMREAD_COLOR);
    resize(image1, image1, { 500,500 });

    if (image1.empty())
    {
        cout << "Could not read the image: " << endl;
        return 1;
    }

    vector<int> lower_bound = { 0,0,5 };

    int low_H = lower_bound[0], low_S = lower_bound[1], low_V = lower_bound[2];
    int high_H = max_value_H, high_S = max_value, high_V = max_value;

    Mat hsvImg, imgThreshold;

    // Convert from BGR to HSV colorspace
    cvtColor(image1, hsvImg, COLOR_BGR2HSV);
    // Detect the object based on HSV Range Values
    inRange(hsvImg, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), imgThreshold = 1);

    /*Mat medianBlurImg, guassianBlurImg;
    medianBlur(image1, medianBlurImg, 9);
    GaussianBlur(image1, guassianBlurImg, Size(1,1), 9, 9);
    imshow("Original Image", image1);
    imshow("Median Blurred Image", medianBlurImg);
    imshow("Guassian Blurred Image", guassianBlurImg);*/

   /* imshow("Original Image", image1);
    imshow("Hsv Image", hsvImg);
    imshow("Threshold Image", imgThreshold);

    imwrite("Image2.jpg", imgThreshold);

    int k = waitKey(0); // Wait for a keystroke in the window

    if (k == 'q') {
        destroyAllWindows();
    }
    return 0;
}*/