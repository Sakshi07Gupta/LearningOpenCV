  #include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // Read original image 
    Mat img = imread("E:\\OPENCVr\\opencv\\REVISION\\images.jfif");

    // Create a window
    namedWindow("TrackBar", 1);
    //Create trackbar to change brightness
    int slider1 = 80;
    createTrackbar("Brightness", "TrackBar", &slider1, 150);
    
    //Create trackbar to change contrast
    int slider2 = 100;
    createTrackbar("Contrast", "TrackBar",&slider2, 200);

    while (true)
    {
        //Change the brightness and contrast of the image 
        Mat dst;
        int Brightness = slider1 - 50;
        double Contrast = slider2 / 50.0;
        img.convertTo(dst, -1, Contrast, Brightness);

        //show the brightness and contrast adjusted image
        imshow("TrackBar", dst);

        // Wait until user press some key for 50ms
        int iKey = waitKey(50);

        //if user press 'ESC' key
        if (iKey == 27)
        {
            break;
        }
    }

    return 0;
}