/*#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat inputImage = imread("E:\\OPENCVr\\opencv\\Task28\\CardImage.png");
	Mat outputImage = Mat::zeros(Size(inputImage.cols, inputImage.rows), image.type());
	namedWindow("Real Image", 0);
	namedWindow("Output Image", 0);


	Point2f srcPoints[] = {
		Point(183,43),
		Point(134,146),
		Point(203,179),
		Point(253,76)
	};

	Point2f dstPoints[] = {
		Point(0,0),
		Point(500,0),
		Point(0,800),
		Point(400,600)
	};

	Mat Matrix = getPerspectiveTransform(srcPoints, dstPoints);
	warpPerspective(image, output, Matrix, cv::Size(500, 800));
	cv::imshow("Real Image", image);
	cv::imshow("Output Image", output);
	cv::waitKey();
	return 0;
}*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp" 
#include<iostream>
using namespace cv;
using namespace std;
int main() {
	int cnt = 1;
	while (cnt++)
	{
		Mat image;
		image = imread("E:\\OPENCVr\\opencv\\Chapter1\\thor.jpg", IMREAD_COLOR);
		Mat output_image = Mat::zeros(Size(1000, 1000), image.type());
		namedWindow("original image", 0);
		namedWindow("output image", 0);
		Point2f inpMat[3];
		Point2f outMat[3];
		inpMat[0] = Point2f(0.0, 0.0);
		inpMat[1] = Point2f(image.cols, 0);
		inpMat[2] = Point2f(0, image.rows);

		outMat[0] = Point2f(0, 200);
		outMat[1] = Point2f(500, 100 + cnt);
		outMat[2] = Point2f(170, 500 - cnt);
		Mat M = getAffineTransform(inpMat, outMat);
		warpAffine(image, output_image, M, output_image.size());

		Point2f center(image.cols / 2, output_image.rows / 2);
		double angle = 50;
		double scale = 0.6;

		Mat M1 = getRotationMatrix2D(center, angle, scale);
        
		Mat dst;
		warpAffine(image, dst, M1, image.size());


		cout << M << endl;
		imshow("original image", image);
		imshow("output image", output_image);
		imshow("Ouput", dst);
		waitKey(1);

	}
	return 0;
}