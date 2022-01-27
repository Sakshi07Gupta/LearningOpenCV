/*#include <iostream>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main() {
    Mat imgCircles, detectImgCircles;

    imgCircles = imread("E:\\OPENCVr\\opencv\\Task23\\Circle1.jpg");
    imgCircles.copyTo(detectImgCircles);

    // Circle Detection Hough Transform

    Mat gray;
    cvtColor(imgCircles, gray, COLOR_RGB2GRAY);

    medianBlur(gray, gray, 5);

    // vector<Vec3f> circles;
    // HoughCircles( gray_image, circles, CV_HOUGH_GRADIENT, 2, 20, 300, 20, 5, 15);

    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 5,
        gray.rows / 8,  // change this value to detect circles with different distances to each other
        10, 30, 25,10 // change the last two parameters
   // (min_radius & max_radius) to detect larger circles
    );

    for (size_t i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle center
        circle(detectImgCircles, center, 1, Scalar(0, 100, 100), 1, LINE_AA);
        // circle outline
        int radius = c[2];

        circle(detectImgCircles, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
    }

    imshow("Original Circle Image", imgCircles);
    imshow("Circle Detection", detectImgCircles);
    waitKey(0);
}*/

