#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
	cv::Mat image = cv::imread("images/diody.jpg");
    cv::resize(image, image, cv::Size(image.rows/3, image.cols/3));


    cv::imshow("OKNO", image);
	cv::waitKey(0);
	return(0);
}

