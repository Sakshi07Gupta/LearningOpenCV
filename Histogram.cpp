#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include "CUDA_Histogram.h"

using namespace std;
using namespace cv;

int main() {

	Mat Input_Image = imread("E:\\OPENCVr\\opencv\\Task7\\tree.jpg"); // Read Color Image

	cout << "Image Height: " << Input_Image.rows << ", Image Width: " << Input_Image.cols << ", Image Channels: " << Input_Image.channels() << endl;

	int Histogram_Blue[256] = { 0 };
	int Histogram_Green[256] = { 0 };
	int Histogram_Red[256] = { 0 };

	Histogram_Calculation(Input_Image.data, Input_Image.rows, Input_Image.cols, Input_Image.channels(), Histogram_Blue, Histogram_Green, Histogram_Red);

	imwrite("Histogram_Image.png", Input_Image);

	for (int i = 0; i < 256; i++) {
		cout << "Histogram_Blue[" << i << "]: " << Histogram_Blue[i] << endl;
		cout << "Histogram_Green[" << i << "]: " << Histogram_Green[i] << endl;
		cout << "Histogram_Red[" << i << "]: " << Histogram_Red[i] << endl;
	}
	system("pause");//to stop when every thing executes
	return 0;
}
