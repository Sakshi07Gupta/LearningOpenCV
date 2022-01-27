/*#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()

{
        // Reading image
        
        Mat img = imread("E:\\OPENCVr\\opencv\\Tak11\\picture.jpg");
    
      // Display original image
        
        imshow("original Image", img);
    
      //   waitKey(0);
    
        // Convert to graycsale
        
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
    
        // waitKey(0);
    
        imshow("Sobel Y", sobely);
        //    waitKey(0);
    
        imshow("Sobel XY using Sobel() function", sobelxy);
    
      //  waitKey(0);
        
        // Canny edge detection
        
        Mat edges;
    
        Canny(img_blur, edges, 100, 200, 3, false);
    
        // Display canny edge detected image
        
        imshow("Canny edge detection", edges);
        waitKey(0);
        destroyAllWindows();
        return 0;
   
}*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
    cv::CommandLineParser parser(argc, argv,
        "{@input   |E:\\OPENCVr\\opencv\\Tak11\\picture.jpg|input image}"
        "{ksize   k|1|ksize (hit 'K' to increase its value at run time)}"
        "{scale   s|1|scale (hit 'S' to increase its value at run time)}"
        "{delta   d|0|delta (hit 'D' to increase its value at run time)}"
        "{help    h|false|show help message}");
    cout << "The sample uses Sobel or Scharr OpenCV functions for edge detection\n\n";
    parser.printMessage();
    cout << "\nPress 'ESC' to exit program.\nPress 'R' to reset values ( ksize will be -1 equal to Scharr function )";
    // First we declare the variables we are going to use
    Mat image, src, src_gray;
    Mat grad;
    const String window_name = "Sobel- Edge Detector";
    int ksize = parser.get<int>("ksize");
    int scale = parser.get<int>("scale");
    int delta = parser.get<int>("delta");
    int ddepth = CV_16S;
    String imageName = parser.get<String>("@input");
    // As usual we load our source image (src)
    image = imread(samples::findFile(imageName), IMREAD_COLOR); // Load an image
    // Check if image is loaded fine
    if (image.empty())
    {
        printf("Error opening image: %s\n", imageName.c_str());
        return EXIT_FAILURE;
    }
    for (;;)
    {
        // Remove noise by blurring with a Gaussian filter ( kernel size = 3 )
        GaussianBlur(image, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
        // Convert the image to grayscale
        cvtColor(src, src_gray, COLOR_BGR2GRAY);
        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y;
        Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);
        Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);
        // converting back to CV_8U
        convertScaleAbs(grad_x, abs_grad_x);
        convertScaleAbs(grad_y, abs_grad_y);
        addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
        imshow(window_name, grad);
        char key = (char)waitKey(0);
        if (key == 27)
        {
            return EXIT_SUCCESS;
        }
        if (key == 'k' || key == 'K')
        {
            ksize = ksize < 30 ? ksize + 2 : -1;
        }
        if (key == 's' || key == 'S')
        {
            scale++;
        }
        if (key == 'd' || key == 'D')
        {
            delta++;
        }
        if (key == 'r' || key == 'R')
        {
            scale = 1;
            ksize = -1;
            delta = 0;
        }
    }
    return EXIT_SUCCESS;
}