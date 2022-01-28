#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
// Declare the variables
Mat src, dst;
int top, bottom, left, right;
int borderType = BORDER_CONSTANT;
const char* window_name = "copyMakeBorder Demo";
//RNG rng(1);
int main()
{
    Mat src= imread("E:\\OPENCVr\\opencv\\Chapter1\\thor.jpg", IMREAD_COLOR);
    // Brief how-to for this program
    printf("\n \t copyMakeBorder Demo: \n");
    printf("\t -------------------- \n");
    printf(" ** Press 'c' to set the border to a random constant value \n");
    printf(" ** Press 'r' to set the border to be replicated \n");
    printf(" ** Press 'ESC' to exit the program \n");
    namedWindow(window_name, WINDOW_AUTOSIZE);
    // Initialize arguments for the filter
    top = (int)(0.05 * src.rows); bottom = top;
    left = (int)(0.05 * src.cols); right = left;
    for (;;)
    {
      //  Scalar value(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        Scalar value(234,221,56);
        copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);
        imshow(window_name, dst);
        char c = (char)waitKey(500);
        if (c == 27)
        {
            break;
        }
        else if (c == 'c')
        {
            borderType = BORDER_CONSTANT;
        }
        else if (c == 'r')
        {
            borderType = BORDER_REPLICATE;
        }
    }
    return 0;
}