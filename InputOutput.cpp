/*#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

////// COLOR DETECTION ///////
Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 19, smax = 255, vmax = 255;
int main()
{
	// string path = "E:\\OPENCVr\\opencv\\learning1\\images.jfif";
	// string path = "E:\\OPENCVr\\opencv\\Assignment2\\input.jpg";
	// string path = "E:\\OPENCVr\\opencv\\Assignment2\\Assignment2\\Image.jpg";

	string path = "E:\\OPENCVr\\opencv\\Assignment2\\Image1.jpg";
	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));

	createTrackbar("hue Min", "Trackbars", &hmin, 179);
	createTrackbar("hue Max", "Trackbars", &hmax, 179);
	createTrackbar("sat Min", "Trackbars", &smin, 255);
	createTrackbar("sat Max", "Trackbars", &smax, 255);
	createTrackbar("val Min", "Trackbars", &vmin, 255);
	createTrackbar("val Max", "Trackbars", &vmax, 255);
	while (true) {

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		imwrite("Image1.jpg", mask);

		Mat Image_blurred_with_5x5_kernel;
		GaussianBlur(mask, Image_blurred_with_5x5_kernel, Size(5, 5), 0);
		waitKey(1);
	}

	return 0;

}*/