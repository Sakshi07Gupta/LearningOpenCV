# Assignment2-> Consider an image and remove the smaller boxes except 2 big box

#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
Mat image;
void locator(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{

		Point p1(x, y);
		Point p2(x + 20, y + 10);
		rectangle(image, p1, p2, Scalar(255, 255, 255), -1, LINE_8);
		imshow("Track", image);
		imwrite("Image11.jpg", image);
	}
}
int main()
{
	image = imread("F:\\OPENcV\\OPENCV\\opencv\\Assignment2\\Assignment2\\BoxImage.jpg");
	namedWindow("Track");
	setMouseCallback("Track", locator, NULL);
	imshow("Track", image);
	
	waitKey(0);
	return 0;
}
