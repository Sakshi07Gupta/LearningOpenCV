/*#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp" 
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	int cnt = 1;
  while(cnt++)
  {
		Mat image;
		image = imread("E:\\OPENCVr\\opencv\\Chapter1\\thor.jpg", IMREAD_COLOR);
		Mat output_image = Mat::zeros(Size(1000,1000), image.type());
		namedWindow("original image", 0);
		namedWindow("output image", 0);
		Point2f inpMat[3];
		Point2f outMat[3];
		inpMat[0] = Point2f(0.0, 0.0);
		inpMat[1] = Point2f(image.cols, 0);
		inpMat[2] = Point2f(0, image.rows);

		outMat[0] = Point2f(0, 200);
		outMat[1] = Point2f(500, 100+cnt);
		outMat[2] = Point2f(170, 500-cnt);
		Mat M = getAffineTransform(inpMat, outMat);
		warpAffine(image, output_image, M, output_image.size());
		cout << M << endl;
		imshow("original image", image);
		imshow("output image", output_image);
		waitKey(1);
	
  }
  return 0;
}*/