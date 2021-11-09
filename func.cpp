#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

void findColor(cv::Mat image)
{
    cv::cvtColor(image, img, cv::COLOR_BGR2HSV);
    cv::Scalar lower(pick.getH(false), pick.getS(false), pick.getV(false));
    cv::Scalar upper(pick.getH(true), pick.getS(true), pick.getV(true));
    cv::inRange(img, lower, upper, mask);

}