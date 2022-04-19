/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;
// int threshold = 200;
int thresh = 140;

int main()
{
    Mat src, gray;
    // Load source image and convert it to gray
    src = imread("F:\\OPENcV\\OPENCV\\opencv\\Task36\\Grids.jpg", 1);
    cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    Mat dst, dst_norm, dst_norm_scaled;
    dst = Mat::zeros(src.size(), CV_32FC1);

    // Detecting corners
   //  cornerHarris(gray, dst, 7, 5, 0.05, BORDER_DEFAULT);
    cornerHarris(gray, dst,2, 3.5, 0.05, BORDER_DEFAULT);


    // Normalizing
    normalize(dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);

    // Drawing a circle around corners
    for (int j = 0; j < dst_norm.rows; j++)
    {
        for (int i = 0; i < dst_norm.cols; i++)
        {
            if ((int)dst_norm.at<float>(j, i) > thresh)
            {
                circle(dst_norm_scaled, Point(i, j), 5, Scalar(0), 2, 8, 0);
            }
        }
    }


    // Showing the result
    // namedWindow("corners_window", );
    imshow("corners_window", dst_norm_scaled);

    waitKey(0);
    return(0);
}*/
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image, gray;
    Mat output, output_norm, output_norm_scaled;

    // Loading the actual image
    image = imread("F:\\OPENcV\\OPENCV\\opencv\\Task36\\Grids.jpg", IMREAD_COLOR);

    // Edge cases
    if (image.empty()) {
        cout << "Error loading image" << endl;
        return -1;
    }
    cv::imshow("Original image", image);
    cv::waitKey();

    // Converting the color image into grayscale
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Detecting corners
    output = Mat::zeros(image.size(), CV_32FC1);
    cornerHarris(gray, output, 7, 5, 0.05);

    // Normalizing
    normalize(output, output_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
    convertScaleAbs(output_norm, output_norm_scaled);

    // Drawing a circle around corners
    for (int j = 0; j < output_norm.rows; j++) {
        for (int i = 0; i < output_norm.cols; i++) {
            if ((int)output_norm.at<float>(j, i) > 100) {
                circle(image, Point(i, j), 5, Scalar(0, 0, 255), 2, 8, 0);
            }
        }
    }

    // Displaying the result
    cv::imshow("Output", image);
    cv::waitKey();
    //cv::imwrite("Detected_circles.jpg", image);
    return 0;
}*/