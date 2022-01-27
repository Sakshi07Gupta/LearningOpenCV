#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//////////////////// Load An Image ///////////////////////
int main()
{
	string path = "E:\\OPENCVr\\opencv\\learning1\\picture.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY); // GRAY SCALE CONVERSION

	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0); // to blur the image

	Canny(imgBlur, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);
	imshow("Image", img);
	imshow("Image GRAY", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dialte", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
	return 0;
}