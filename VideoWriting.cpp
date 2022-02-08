/*#include"opencv2\opencv.hpp"
#include"opencv2\highgui.hpp"

int main() {

	// Create video Capturing object // 0 is for webcam
	cv::VideoCapture video(0);

	// Check That video opened 
	if (!video.isOpened())
		return -1;
	// for saving the frame
	cv::Mat frame;

	// Get video resolution
	int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
	int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);
     

	// Createvideo writer object
	cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeigth));
	while (video.read(frame))
	{
		// Display the frame
		cv::imshow("video feed", frame);

		// Write video frame
		output.write(frame);

		// for ending the video early 
		if (cv::waitKey(25) >= 0)
		{
			break;
		}
	}

	// Realse video capture and 
	output.release();
	video.release();

	cv::destroyAllWindows();

	return 0;
}*/