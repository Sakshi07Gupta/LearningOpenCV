/*#include <Windows.h>
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/video/tracking.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat Image;
	
	Image = imread("E:\\OPENCVr\\opencv\\Chapter1\\thor.jpg", IMREAD_COLOR);
	//I would like to visualize Mat step by step to see the result immediately.

	// Show what is in the Mat after load

	namedWindow("Step 1", WINDOW_AUTOSIZE); // Image is loaded
	imshow("Step 1", Image);

	// Same the result from LoadedImage to Step1.JPG
	imwrite("Step1.JPG", Image);

	//Rectangle Rec start at x=195 y=126, width=114 and heigth=99
	Rect Rec(195, 126, 114, 99);


	//Draw the rectangle into LoadedImage
   //Parameters are (into Mat, Rec describe position where to draw rectangle
   // Scalar is Color, 1 is thickness, 8 is line type and 0 shift position
	rectangle(Image, Rec, Scalar(255), 1, 8, 0);


	// Show what rectangle
	namedWindow("Step 2 draw Rectangle", WINDOW_AUTOSIZE);
	imshow("Step 2 draw Rectangle",Image);
	

	// Same the result from LoadedImage to Step2.JPG
	imwrite("Step2.JPG", Image);

	//Select area described by REC and result write to the Roi

	Mat Roi = Image(Rec);
	namedWindow("Step 3 Draw selected Roi", WINDOW_AUTOSIZE);
	imshow("Step 3 Draw selected Roi", Roi);

	// Same the result from LoadedImage to Step3.JPG
	imwrite("Step3.JPG", Roi);

	// Put roi back into source image
 // If you want to show the detail and  visualize with context of source image
 //  This rectangle describe target, where we want to put our roi into original image
 //  width and height of where rect must match Roi size
 // Let put our Roi into origin
	Rect WhereRec(81, 126, Roi.cols, Roi.rows);
	Rect WhereRec1(308, 126, Roi.cols, Roi.rows);
	Rect WhereRec2(419, 126, Roi.cols, Roi.rows);

	// This copy Roi Image into loaded on position Where rec

	Roi.copyTo(Image(WhereRec));
	Roi.copyTo(Image(WhereRec1));
	Roi.copyTo(Image(WhereRec2));
	namedWindow("Step 4  Final result", WINDOW_AUTOSIZE);
	imshow("Step 4 Final result", Image);

	waitKey(0);
	// Same the result from LoadedImage to Step4.JPG
	imwrite("Step4.JPG", Image);
	destroyAllWindows();
}*/
