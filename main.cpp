#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	cv::Mat image;
    image=cv::imread("test.png");
	cv::Mat imageErode, gaussinImg;
	cv::GaussianBlur(image, gaussinImg, cv::Size(3,3), 100, 5);
	cv::Canny(gaussinImg, imageErode, 25,200);
    cv::imshow("ELO KUREWKI", image);
	cv::imshow("CANNY", imageErode);
	cv::imshow("GAUSIAN", gaussinImg);
	cv::waitKey(0);
	return(0);
}

