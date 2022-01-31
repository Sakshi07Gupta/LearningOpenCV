/#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat image = imread("E:\\OPENCVr\\opencv\\Task28\\CardImage.png");
	namedWindow("Real Image", 0);
	namedWindow("Output Image", 0);

	Mat output;

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
		Point(500,800)
	};

	Mat Matrix = getPerspectiveTransform(srcPoints, dstPoints);
	warpPerspective(image, output, Matrix, cv::Size(500,800));
     cv:: imshow("Real Image", image);
	 cv:: imshow("Output Image", output);
    cv :: waitKey();
	return 0;
}