#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //Load the image
    Mat img = imread("E:\\OPENCVr\\opencv\\Assignment1\\Grids.jpg");

    //Show source image
    imshow("Image", img);

    Mat gray_img; // changing colored img into gray
    if (img.channels() == 3)
    {
        cvtColor(img, gray_img, COLOR_BGR2GRAY);
    }
    else
    {
        gray_img = img;
    }
    imshow("gray", gray_img);

    //Apply adaptiveThreshold at the bitwise_not of gray, notice the ~ symbol
    Mat bW;
    adaptiveThreshold(~gray_img, bW, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -1);
    imshow("binary", bW);

    Mat edge, draw;
    Canny(gray_img, edge, 50, 150, 3);

    edge.convertTo(draw, CV_8U);
    vector<Vec2f> lines;
    HoughLines(detectImgLines, lines, 1, CV_PI, 150);
    for (size_t i = 0; i < lines, size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][i]
    }
    imshow("Canny Image", draw);

    waitKey(0);
    return 0;
}