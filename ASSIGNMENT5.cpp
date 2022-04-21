# Assignment5-> Color spacing with (Lab, RGB, YCrCb, CYMK)
    


#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main() {
    Mat img;
    // Mat img1;
   // img1 = imread("F:\\OPENcV\\OPENCV\\opencv\\Assignment1\\rub02.jpg");
    img = imread("F:\\OPENcV\\OPENCV\\opencv\\Assignment1\\picture.jpg");
    Mat Lab_image;
    Mat Hsv_image;
    Mat Rgb_image;
    Mat YCrCb_image;
    // Mat Lab_image1,Mat Hsv_image1,Mat Rgb_image2;
    cv::cvtColor(img, Lab_image, cv::COLOR_BGR2Lab);
    cv::cvtColor(img, Hsv_image, cv::COLOR_BGR2HSV);
    cv::cvtColor(img, Rgb_image, cv::COLOR_BGR2RGB);
    cv::cvtColor(img, YCrCb_image, cv::COLOR_BGR2YCrCb);
    //cv::cvtColor(img1, Rgb_image1, cv::COLOR_BGR2RGB);
    //cv::cvtColor(img1, Lab_image1, cv::COLOR_BGR2Lab);
    // cv::cvtColor(img1, Hsv_image1, cv::COLOR_BGR2HSV);
   // cv::cvtColor(img1, Rgb_image2, cv::COLOR_BGR2RGB);
    
    imshow("img", img);
   // imshow("img1", img1);
    imshow("Lab image", Lab_image);
    imshow("Hsv image", Hsv_image);
    imshow("RGB image", Rgb_image);
    imshow("YCrCb_image", YCrCb_image);
   // imshow("Lab_image1", Rgb_image1);
    // imshow("Hsv_image1", Rgb_image1);
   // imshow("Rgb_image2", Rgb_image2);
    waitKey(0);
    return 0;
}

Test rgb2cmyk function
int main(int argc, char** argv) {
    // TODO: change filename
    cv::Mat src = cv::imread("F:\\OPENcV\\OPENCV\\opencv\\Assignment1\\picture.jpg");
    std::vector<cv::Mat> dst;
    rgb2cmyk(src, dst);

    // Display results
    cv::imshow("src", src);
    cv::imshow("c", dst[0]);
    cv::imshow("m", dst[1]);
    cv::imshow("y", dst[2]);
    cv::imshow("k", dst[3]);

    cv::waitKey();
    return 0;
}
