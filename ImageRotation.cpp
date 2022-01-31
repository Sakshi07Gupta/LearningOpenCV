#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp" 
#include<iostream>
using namespace cv;
using namespace std;
int main() {

		Mat image;

		image = imread("E:\\OPENCVr\\opencv\\Chapter1\\thor.jpg", IMREAD_COLOR);
		Mat output_image = Mat::zeros(Size(800, 800), image.type());
		namedWindow("original image", 0);
		//namedWindow("output image", 0);
		namedWindow("Rotated by 30", 0);
		namedWindow("Rotated by 40", 0);
		namedWindow("Rotated by 50", 0);
		namedWindow("Rotated by 120", 0);

		Point2f center(image.cols/ 2, image.rows/ 2);
		double angle = -30;
		double angle1 = 40;
		double angle2 = 45;
		double angle3 = 50;
		double angle4 = 120;

		double scale = 0.5;
		Mat M1 = getRotationMatrix2D(center, angle, scale);
		Mat M2 = getRotationMatrix2D(center, angle1, scale);
		Mat M3 = getRotationMatrix2D(center, angle2, scale);
		Mat M4 = getRotationMatrix2D(center, angle3, scale);
		Mat M5 = getRotationMatrix2D(center, angle4, scale);
		Mat Final, Final1, Final2, Final3;
		warpAffine(image, Final, M1, image.size());
		warpAffine(image, Final1, M2, image.size());
		warpAffine(image, Final2, M4, image.size());
		warpAffine(image, Final3, M5, image.size());

		imshow("original image", image);
		//imshow("output image", output_image);
		imshow("Rotated by -30", Final);
		imshow("Rotated by 40", Final1);
		imshow("Rotated by 50", Final2);
		imshow("Rotated by 120", Final3);
		waitKey(0);
		return 0;
	

}
