#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

// Function which do opening operation on image
int openingMorphological()
{
    // Reading the Image
    Mat image = imread( "E:\\OPENCVr\\opencv\\Chapter1\\girl.jpg", IMREAD_GRAYSCALE);

    // Create a structuring element
    int morph_size = 1;
    Mat element = getStructuringElement( MORPH_CROSS,  Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));
    Mat output;

    // Opening
    morphologyEx(image, output, MORPH_OPEN, element, Point(-1, -1), 1);

    // Closing
    morphologyEx(image, output, MORPH_CLOSE, element,  Point(-1, -1), 2);
    
    imshow("Image", image);
    imshow("Opening", output);
    imshow("Closing", output);
    waitKey();
    destroyAllWindows();

    return 0;
}

// Function calling
int main()
{

    openingMorphological();

    return 0;
}
