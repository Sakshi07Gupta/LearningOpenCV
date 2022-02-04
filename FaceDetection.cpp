/*//#include<opencv2 / imgcodecs.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<iostream>
#include<stdlib.h>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("E:\\OPENCVr\\opencv\\learning1\\a.jpg");
	CascadeClassifier faceDetection; // we are loading cascade here
	// faceDetection.load("E:\\OPENCVr\\opencv\\sources\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml"); // this is not working
	// faceDetection.load("E:\\OPENCVr\\opencv\\learning1\\haarcascade_frontalface_alt2.xml");
	faceDetection.load("E:\\OPENCVr\\opencv\\learning1\\haarcascade_frontalface_alt.xml");

	if (faceDetection.empty())
	{
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> faces; // data type Rect has the method of topLeft and bottomRight 
	faceDetection.detectMultiScale(img, faces, 1.2, 10); // 1 is a scale fqactor and 10 is minimum neighbours 

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 1);

	}

	imshow("Image", img);
	waitKey(0);

}*/
