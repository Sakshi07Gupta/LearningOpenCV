#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main() {

    Mat imgLines, detectImgLines, detectImgLinesP;
    imgLines = imread("E:\\OPENCVr\\opencv\\Task23\\images.png");
   

    imgLines.copyTo(detectImgLines);
    imgLines.copyTo(detectImgLinesP);
   
    // Line Detection Hough Transform
    // Edge detection
    Canny(imgLines, detectImgLines, 200, 255); // 200 and 255 are threshold values



    // vector<Vector2f> hough_lines;
    // HoughLines(binary_edge_image, hough_lines, 1, PI/200.0, 60);
   
    // Standard Hough Line Transform
    vector<Vec2f> lines; // will hold the results of the detection
    HoughLines(detectImgLines, lines, 1, CV_PI, 150); // runs the actual detection 
   
   // 1 is rho(in pixel)  CV_PI is theta(degree) 150 is threshold value 
   
   // Draw the lines
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];  /// ith = rho 0th =  theta
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b)); // this is the formula 
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        line(detectImgLines, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
    }

    // Display
    imshow("Original Line Image", imgLines);
    imshow("Line Detection", detectImgLines);
    waitKey(0);

   /* // Probabilistic Line Transform
    Canny(imgLines, detectImgLinesP, 200, 255);

    // vector<Vec4i> line_segment;
    // HoughLinesP(binary_edge_image, line_segments, 1.0,200.0,20,20,5)

    //  binary egde image is dst , line segment is parameter is vector 
    // that stores the parameter(points of lines) of the detected lines
    // 1 is rho here (in pixel) 
    // 200.0 is theta (CV_PI/180 when we write like this it means we use it in degrees)
    // 20 is threshold value
    // 20 is minLineLength: The minimum number of points that can form a line. 
    // Lines with less than this number of points are disregarded.
    // 5 is maxLineGap: The maximum gap between two points to be considered in the same line.


    vector<Vec4i> linesP; // will hold the results of the detection
    HoughLinesP(detectImgLinesP, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection

    // Draw the lines
    for (size_t i = 0; i < linesP.size(); i++)
    {
        Vec4i l = linesP[i];
        line(detectImgLinesP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
    }

    imshow("Original Line Image", imgLines);
    imshow("Line Detection P", detectImgLinesP);*/
   waitKey(0);
    return 0;
}