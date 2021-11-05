#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	cv::Mat image;
    image=cv::imread("images/test.png");
	cv::circle(image, cv::Point(100,100), 40, cv::Scalar(43, 105, 63), cv::FILLED);
	cv::Mat imageCanny, gaussinImg;
	cv::GaussianBlur(image, gaussinImg, cv::Size(3,3), 100, 5);
	cv::Canny(gaussinImg, imageCanny, 25,200);
	cv::putText(image, "INPUT", cv::Point(10, 20), cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255, 101, 197), 2);
	cv::putText(imageCanny, "CANNY", cv::Point(10, 20), cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255, 101, 197), 2);
	cv::putText(gaussinImg, "GAUSS", cv::Point(10, 20), cv::FONT_HERSHEY_DUPLEX, 0.7, cv::Scalar(255, 101, 197), 2);
    cv::imshow("ELO KUREWKI", image);
	cv::imshow("CANNY", imageCanny);
	cv::imshow("GAUSIAN", gaussinImg);
	cv::waitKey(0);
	return(0);
}

