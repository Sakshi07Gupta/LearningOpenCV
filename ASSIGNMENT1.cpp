# Assignment 1 -> To detect horizontal and vertical lines in an image.


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("F:\\OPENcV\\OPENCV\\opencv\\Assignment1\\Image1.jpeg");

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
    // The images that will use to extract the horizontal line
       Mat horizontal = bW.clone();
        //Specify size on horizontal axis
       int horizontalsize = horizontal.cols / 20;
        //Create structure element for extracting horizontal lines through morphology operations
      Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontalsize, 1));
        //Apply morphology operations
        erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
        dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));
        imshow("horizontal", horizontal);

        // The images that will use to extract the vertical lines
       Mat vertical = bW.clone();
        //Specify size on vertical axis
        int verticalsize = vertical.rows / 20 ;
        //Create structure element for extracting vertical lines through morphology operations
       Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, verticalsize));
        //Apply morphology operations
        erode(vertical, vertical, verticalStructure, Point(-1, -1));
        dilate(vertical, vertical, verticalStructure, Point(-1, -1));
     
      imshow("vertical", vertical);

    waitKey(0);
    return 0;
}
