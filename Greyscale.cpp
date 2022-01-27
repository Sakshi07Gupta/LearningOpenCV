#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp> // basic building blocks
#include <opencv2/imgcodecs.hpp> // capabilities for reading and writing images 
#include <opencv2/highgui.hpp> // view an image in a window
#include <opencv2/imgproc.hpp> // for cvtColor

using namespace std;
using namespace cv;


int main()
{
		Mat img;
	// load the image
	img = imread("E:\\OPENCVr\\opencv\\Task2\\picture.jpg", IMREAD_COLOR);

	Mat gray_img;
	cvtColor(img, gray_img, COLOR_BGR2GRAY);

	Mat binary_img;
	cvtColor(gray_img, binary_img, THRESH_BINARY);

	// imwrite(argv[1], gray_img);
	imshow("color image", img);
	 imshow("gray image", gray_img);
	 imshow("binary image", binary_img);
	waitKey(0);
	destroyAllWindows();

	return 0;
}


