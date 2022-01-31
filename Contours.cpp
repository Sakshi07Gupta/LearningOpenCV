/*#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat zeros;
	Mat frame = Mat:: zeros(Size(1000, 1000), CV_8UC3);
	namedWindow("output", 0);

	std::vector < std::vector<cv::Point>> contours = 
	{
		{cv::Point(100,100), cv::Point(100,150), cv::Point(150,150)},
		{cv::Point(300,300), cv::Point(400,400)},
		{cv::Point(100,300), cv::Point(200,400)},
		{cv::Point(200,300), cv::Point(0,300), cv::Point(450,550), cv::Point(600,800)},
		{cv::Point(100,250), cv::Point(80,340), cv::Point(500,750), cv::Point(900,950),cv::Point(990,930)}  

	};
	for (int i = 0; i < contours.size(); i++)
		drawContours(frame, contours, i, Scalar(0, 255, 45), 5);

	imshow("output", frame);
	waitKey(0);
	return 0;

}*/