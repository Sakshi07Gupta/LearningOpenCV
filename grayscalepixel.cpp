#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp> // basic building blocks
#include <opencv2/imgcodecs.hpp> // capabilities for reading and writing images 
#include <opencv2/highgui.hpp> // view an image in a window
#include <opencv2/imgproc.hpp> // for cvtColor
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
void get_rgb(Mat image, int x, int y)
{    
	int b = image.at<Vec3b>(x,y)[0];//getting the pixel values//
	int g = image.at<Vec3b>(x,y)[1];//getting the pixel values//
	int r = image.at<Vec3b>(x, y)[2];//getting the pixel values//
	cout << "Value of blue channel:" << b << endl;//showing the pixel values//
	cout << "Value of green channel:" << g << endl;//showing the pixel values//
	cout << "Value of red channel:" << r << endl;//showing the pixel values//
}
int main() {
	int x;
	cout << "Type the x-coordinate: "; // Type a number and press enter
	cin >> x;
	int y;
	cout << "Type the y-coordinate: "; // Type a number and press enter
	cin >> y;
	Mat image;//taking an image matrix//
	image = imread("E:\\OPENCVr\\opencv\\Task6\\tree.jpg");//loading an image//
	
	get_rgb(image, x, y);
	// get_rgb(x, y);
	waitKey(0);
		system("pause");//pause the system to visualize the result//
	return 0;
}
