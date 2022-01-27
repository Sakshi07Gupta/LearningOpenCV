#include "iostream"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

int main()
{
    Mat img;
   
    img = imread("E:\\OPENCVr\\opencv\\Task2\\picture.jpg", IMREAD_COLOR);
    const char* window = "Image Pyramids";
 //  const char *i = (char)namedWindow("Image Pyramids", 1);
   
    for (;;)
    {
        imshow(window, img);
        char c = (char)waitKey(0);
        if (c == 27)
        {
            break;
        }
        else if (c == 'g')
        {
            pyrUp(img, img, Size(img.cols * 2, img.rows * 2));
            printf(" Zoom In: Image x 2 \n");
        }
        else if (c == 'h')
        {
            pyrDown(img, img, Size(img.cols / 2, img.rows / 2));
            printf("Zoom Out: Image / 2 \n");
        }
    }
    return 0;
}