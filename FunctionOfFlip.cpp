/*#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("E:\\OPENCVr\\opencv\\Chapter1\\noisy.jpg");
	imshow("Original Image", src);
	if (!src.data) {
		return -1;
	}
	while (1)
	{
		char p = waitKey();
		if (p == 'h')
		{
			Mat dst;
			flip(src, dst, 1); // horizonatal flip;
			imshow("horizontal", dst);
		}
		else if (p == 'v')
		{
			Mat dst;
			flip(src, dst, 0); // vertical flip;
			imshow("vertical", dst);
		}
		if (p == 'b')
		{
			Mat dst;
			flip(src, dst, -1); // both flip;
			imshow("horizontal", dst);
		}
		if (p == 'x')
		{
		   destroyAllWindows();
		}
	}
	return 0;
}*/

#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
char window_name[50] = "img";

void img_flip() {
	Mat img;
	char f_mode;
	cout << " Flip Control ..... h = horizontal v = vertical" << endl;
	cout << " Select Mode: ";
	cin >> f_mode;
	switch (f_mode) {
	case 'h':
		flip(src, img, 1);
		break;

	case 'v':
		flip(src, img, 0);
		break;

	default:
		cout << "try again";

	}
	imshow(window_name, img);
}

int main() {
	src = imread("E:\\OPENCVr\\opencv\\Chapter1\\hero1.jpg");
	imshow("original image", src);
		img_flip();
		waitKey(0);
		
	return 0;
}