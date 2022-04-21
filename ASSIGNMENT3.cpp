# Assignment 3-> We have input image and expected output image so for that I have to write algo. 
# Assignment 3-> I hasve input image which has some distortion and holes/ which I have to remove and for that we have write algo.

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const int max_value_H = 179;
const int max_value = 255;

int main()
{
    string path = "E:\\OPENCVr\\opencv\\Assignment2\\Assignment2\\Image1.jpg";
    Mat image1 = imread(path, IMREAD_COLOR);
    resize(image1, image1, { 500,500 });

    if (image1.empty())
    {
        cout << "Could not read the image: " << endl;
        return 1;
    }

    vector<int> lower_bound = {0,0,5};

    int low_H = lower_bound[0], low_S = lower_bound[1], low_V = lower_bound[2];
    int high_H = max_value_H, high_S = max_value, high_V = max_value;

    Mat hsvImg, imgThreshold;

    // Convert from BGR to HSV colorspace
    cvtColor(image1, hsvImg, COLOR_BGR2HSV);
    // Detect the object based on HSV Range Values
    inRange(hsvImg, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), imgThreshold=1);

    /*Mat medianBlurImg, guassianBlurImg;
    medianBlur(image1, medianBlurImg, 9);
    GaussianBlur(image1, guassianBlurImg, Size(1,1), 9, 9);
    imshow("Original Image", image1);
    imshow("Median Blurred Image", medianBlurImg);
    imshow("Guassian Blurred Image", guassianBlurImg);

    imshow("Original Image", image1);
    imshow("Hsv Image", hsvImg);
    imshow("Threshold Image", imgThreshold);

    imwrite("Image2.jpg", imgThreshold);

    int k = waitKey(0); // Wait for a keystroke in the window

    if (k == 'q') {
        destroyAllWindows();
    }
    return 0;
}

after that some holes still there in output image so for that we need to write 2nd algo 



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
	image = imread("F:\\OPENcV\\OPENCV\\opencv\\Assignment2\\Assignment2\\Image1.jpg");
	namedWindow("Track");
	setMouseCallback("Track", locator, NULL);
	imshow("Track", image);
	
	waitKey(0);
	return 0;
}
