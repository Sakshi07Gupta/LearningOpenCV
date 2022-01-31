/*#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {

	// read the image

	Mat image = imread("E:\\OPENCVr\\opencv\\Task24\\building.jpg");
	Mat img_gray;
	cvtColor(image, img_gray, COLOR_BGR2GRAY);
	Mat thresh;
	threshold(img_gray, thresh, 140, 255, THRESH_BINARY);
	imshow("Binary mage", thresh);
	waitKey(0);
	imwrite("image_thres1.jpg", thresh);

	destroyAllWindows();
	// detect the contours on the binary image using cv2.CHAIN_APPROX_NONE

	vector<vector<Point>> contours;

	vector<Vec4i> hierarchy;

	findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	// here thresh is the image in binary form 
	// RETR_TREE is the mode of contour retrieval 
	// CHAIN_APPROX_NONE is the method of contour approximation
	// draw contours on the original image

	Mat image_copy = image.clone();
	// image_cpy is the image 
    // -1 is the contourIndex
	// (0,255,0) is the color code
	// line type = LINE_AA
	// thickness= 2
	drawContours(thresh, contours, -1, Scalar(0, 23, 200), 3);
	drawContours(image_copy, contours, -1, Scalar(0, 255, 0), 2);

	imshow("contours", image_copy);
	imshow("Contours1", thresh);
	

	waitKey(0);

	imwrite("contours_none_image1.jpg", image_copy);
	imwrite("contours_none_image1.jpg", thresh);

	destroyAllWindows();
}*/
