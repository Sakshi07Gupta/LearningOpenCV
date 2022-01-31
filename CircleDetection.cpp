#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace std;
int main()
{
    Mat img;
    img = imread("E:\\OPENCVr\\opencv\\Task18\\Circle.jfif", IMREAD_COLOR);
    imshow("Image", img);
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    medianBlur(gray, gray, 5);
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
        gray.rows /10,  // change this value to detect circles with different distances to each other
        98, 30, 1,60 // change the last two parameters
   // (min_radius & max_radius) to detect larger circles
    );
    for (size_t i = 0; i < circles.size(); i++)
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        // circle outline
        int radius = c[2];
        circle(img, center, radius, Scalar(255, 0, 255), 2, LINE_AA);
    }
    imshow("detected circles", img);
    waitKey();
    return 0;
}