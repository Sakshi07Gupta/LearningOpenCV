/*#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp> // basic building blocks
#include <opencv2/imgcodecs.hpp> // capabilities for reading and writing images 
#include <opencv2/highgui.hpp> // view an image in a window
#include <opencv2/imgproc.hpp> // for cvtColor
using namespace cv;

class Histogram {
public:
	Mat calc_histogram(Mat scr) {
		Mat hist;
		hist = Mat::zeros(256, 1, CV_32F);
		scr.convertTo(scr, CV_32F);
		double value = 0;
		for (int i = 0; i < scr.rows; i++)
		{
			for (int j = 0; j < scr.cols ; j++)
			{ 
				value = scr.at<float>(i, j);
				hist.at<float>(value) = hist.at<float>(value) + 1;
			}
		}
		return hist;
	}
	void plot_histogram(Mat histogram) {
		Mat histogram_image(400, 512, CV_8UC3, Scalar(0, 0, 0));
		Mat normalized_histogram;
		normalize(histogram, normalized_histogram, 0, 400, NORM_MINMAX, -1, Mat());

		for (int i = 0; i < 256; i++)
		{
			rectangle(histogram_image, Point(2 * i, histogram_image.rows - normalized_histogram.at<float>(i)),
				Point(2 * (i + 1), histogram_image.rows), Scalar(255, 0, 0));

		}
		namedWindow("histogram", WINDOW_NORMAL);
		imshow("histogram", histogram_image);
	}
};

void main()
{
	Mat img;
	img = imread("E:\\OPENCVr\\opencv\\Task7\\tree.jpg", 0);
	Histogram H1;
	Mat hist = H1.calc_histogram(img);
	H1.plot_histogram(hist);

	waitKey(0);
}*/

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | E:\\OPENCVr\\opencv\\Task7\\tree.jpg | input image}");
    Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
    if (src.empty())
    {
        return EXIT_FAILURE;
    }
    vector<Mat> bgr_planes;
    split(src, bgr_planes);
    int histSize = 256;
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange[] = { range };
    bool uniform = true, accumulate = false;
    Mat b_hist, g_hist, r_hist;
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }
    imshow("Source image", src);
    imshow("calcHist Demo", histImage);
    waitKey();
    return EXIT_SUCCESS;
}


/*#include <iostream>
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
}*/