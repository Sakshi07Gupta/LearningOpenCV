#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat src;
	
		src = imread("E:\\OPENCVr\\opencv\\Chapter1\\hand.jpg"); // read input image
		imshow("image", src);
		Mat gray, blur_img, threshold_output;
		
			cvtColor(src, gray, COLOR_BGR2GRAY); // convert to grayscale
			imshow("binary", gray);
			blur(gray, blur_img, Size(3, 3)); // apply blur to grayscaled image
			imshow("blur Image", blur_img);
			threshold(blur_img, threshold_output, 245, 255, THRESH_BINARY_INV); // apply binary thresholding
			imshow("threshold image", threshold_output);
			vector< vector<Point> > contours; // list of contour points
			
				vector<Vec4i> hierarchy;
			
				// find contours
			  //findContour allows us to find those connectionsand returns the 
			 //points that form a contour as a list.

				findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE, Point(0,0));
				// create hull array for convex hull points
				
					vector< vector<Point> > hull(contours.size());
				
					for (int i = 0; i < contours.size(); i++)
						
						convexHull(Mat(contours[i]), hull[i], true);

					// create a blank image (black image)
					
						 Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
					
						for (int i = 0; i < contours.size(); i++)
						{

							Scalar color_contours = Scalar(0, 255, 0); // green - color for contours

							Scalar color = Scalar(255, 0, 0); // blue - color for convex hull

							// draw ith contour

							drawContours(drawing, contours, i, color_contours, 1, 8, vector<Vec4i>(), 0, Point());
							imshow("contours", contours);
							// draw ith convex hull

							drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
						}

						imshow("hull", hull);
						waitKey(0);
						destroyAllWindows();
}

