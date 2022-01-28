/*#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main()
{
    // Creating a blank image with white background
    Mat image1(350, 350, CV_8UC3, Scalar(255, 255, 255));//Declaring a white matrix
    Mat image2(350, 350, CV_8UC3, Scalar(255, 255, 255));
    Mat image3(350, 350, CV_8UC3, Scalar(255, 255, 255));
    Mat image4(350, 350, CV_8UC3, Scalar(255, 255, 255));
    Mat image5(500, 500, CV_8UC3, Scalar(255, 255, 255));

    // Top Left Corner
    Point p1(30, 30);

    // Bottom Right Corner
    Point p2(255, 255);

    Point p3(165,234); 
    Point p4(0, 50);

    Point p5(100, 10);
    int radius = 100, thickness = 2;

    Point center(50, 60);//Declaring the center point

    Size xy(50, 90);//Declaring the major and minor axis of the ellipse//

    int angle = 50;//angle of rotation//

    int starting_point = 150;//Starting point of the ellipse//

    int ending_point = 360;//Ending point of the ellipse//

    Scalar line_Color(240, 100, 0);//Color of the Ellipse//

    rectangle(image1, p1, p2, Scalar(255, 0, 0), thickness, LINE_8);
    circle(image2, p3, radius, Scalar(233, 89, 100), thickness=8, LINE_AA);
    line(image3, p4, p5, Scalar(100, 140, 180), thickness=10, LINE_4);
// line(image, (400,450),( p5, Scalar(100, 140, 180), thickness = 10, LINE_4);
    ellipse(image4, center, xy, angle, starting_point, ending_point, line_Color, thickness=6);//Drawing the ellipse

    string str;
    cout << "enter string to be printed" << endl;
    cin >> str;
    putText(image5,str, Point(130,250), FONT_HERSHEY_PLAIN, 10, Scalar(0, 100, 255), thickness = 5, LINE_8, false);

    
    imshow("rectangle", image1);
    imshow("circle", image2);
    imshow("line", image3);
    imshow("ellipse", image4);
    imshow("text", image5);
    waitKey(0);

    return 0;
}*/