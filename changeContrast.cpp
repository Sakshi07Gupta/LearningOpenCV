#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread("E:\\OPENCVr\\opencv\\Task9\\picture.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }
    Mat new_image = Mat::zeros(image.size(), image.type());
    double alpha = 1.0; // Simple contrast control 
    int beta = 0;       // Simple brightness control 
    cout << " Basic Linear Transforms " << endl;
    
    cout << "* Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
  cout << "* Enter the beta value [0-100]: ";   
    cin >> beta;
    for (int y = 0; y < image.rows; y++) /// y is the row
    {
        for (int x = 0; x < image.cols; x++) // x is the column
        {
            for (int c = 0; c < image.channels(); c++) // c is B, G, R 
            {
                new_image.at<Vec3b>(y, x)[c] =  saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
            }
        }
    }
    imshow("Original Image", image);
    imshow("contrast image", new_image);
    waitKey();
    return 0;
}
