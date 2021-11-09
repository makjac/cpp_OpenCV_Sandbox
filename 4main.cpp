#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "src/colorpicker.h"
#include <iostream>

using namespace std;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == cv::EVENT_LBUTTONDOWN )
     {
          Colorpicker* pick = (Colorpicker*)userdata;
          pick->setPoint(x, y);
     }
}



int main()
{
	cv::Mat image = cv::imread("images/diody.jpg"); 
    cv::Mat img, mask;
    cv::resize(image, image, cv::Size(500, 500));
    cv::cvtColor(image, img, cv::COLOR_BGR2HSV);
    Colorpicker pick(img);
    cv::Point p;
    cv::Scalar color;

    cv::namedWindow("SOURCE", 2);
    cv::setMouseCallback("SOURCE", CallBackFunc, &pick);
    for(;;)
    {
    cv::Scalar lower(pick.getH(false), pick.getS(false), pick.getV(false));
    cv::Scalar upper(pick.getH(true), pick.getS(true), pick.getV(true));

    cv::cvtColor(image, img, cv::COLOR_BGR2HSV);
    cv::inRange(img, lower, upper, mask);

	cv::imshow("SOURCE", image);
    cv::imshow("MASK", mask);
	cv::waitKey(1);
    }
	return(0);
}

