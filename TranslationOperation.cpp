#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp" 
#include<iostream>
using namespace cv;
using namespace std;

int main() {


	// read the image
	Mat image = imread("E:\\OPENCVr\\opencv\\Chapter1\\thor.jpg");
	// get the height and width of the image
	int height = image.cols;
	int width = image.rows;
	// get tx and ty values for translation

	float tx = float(width) / 2;
	float ty = float(height) / 2;

	float tx1 = float(width) / 4;
	float ty1 = float(height) / 4;
	
	float tx2 = float(width) / 8;
	float ty2 = float(height) / 8;

	float tx3 = float(width) / 3;
	float ty3 = float(height) / 3;

	// create the translation matrix using tx and ty

	float warp_values[] = { 2.0, 0.0, tx, 0.0, 2.0, ty };
	float warp_values1[] = { 1.0, 0.0, tx1, 0.0, 1.0, ty1 };
	float warp_values2[] = { 1.0, 0.0, tx2, 0.0, 1.0, ty2 };
	float warp_values3[] = { 1.0, 0.0, tx3, 0.0, 1.0, ty3 };

	Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
	Mat translation_matrix1 = Mat(2, 3, CV_32F, warp_values1);
	Mat translation_matrix2 = Mat(2, 3, CV_32F, warp_values2);
	Mat translation_matrix3 = Mat(2, 3, CV_32F, warp_values3);

	// save the resulting image in translated_image matrix

	Mat translated_image;
	Mat translated_image1;
	Mat translated_image2;
	Mat translated_image3;


	// apply affine transformation to the original image using the translation matrix

	warpAffine(image, translated_image, translation_matrix, image.size());
	warpAffine(image, translated_image1, translation_matrix1, image.size());
	warpAffine(image, translated_image2, translation_matrix2, image.size());
	warpAffine(image, translated_image3, translation_matrix3, image.size());
	//display the original and the Translated images

	imshow("Translated image", translated_image);
	imshow("Translated image1", translated_image1);
	imshow("Translated image2", translated_image2);
	imshow("Translated image3", translated_image3);

	imshow("Original image", image);

	waitKey(0);

	// save the translated image to disk

	imwrite("translated_image.jpg", translated_image);
	imwrite("translated_image1.jpg", translated_image1);
	imwrite("translated_image2.jpg", translated_image2);
	imwrite("translated_image3.jpg", translated_image3);
}
