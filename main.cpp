#include <opencv2/highgui.hpp>

int main()
{
	cv::Mat image;
    image=cv::imread("test.png");
    cv::imshow("ELO", image);
	cv::waitKey(0);
	return(0);
}
