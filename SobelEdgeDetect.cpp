#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
        Mat img = imread("E:\\OPENCVr\\opencv\\Task 15\\tree.jpg");
        imshow("original Image", img);
      
        Mat img_gray;
    
        cvtColor(img, img_gray, COLOR_BGR2GRAY);
    
        // Blur the image for better edge detection
        
        Mat img_blur;
    
        GaussianBlur(img_gray, img_blur, Size(3, 3), 0);
    
        // Sobel edge detection
        
       Mat sobelx, sobely, sobelxy;
    
        Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
    
        Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
    
        Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);
    
        // Display Sobel edge detection images
        
        imshow("Sobel X", sobelx);
        imshow("Sobel Y", sobely);
        imshow("Sobel XY using Sobel() function", sobelxy);
   
        waitKey(0);
        destroyAllWindows();
        return 0;
   
}