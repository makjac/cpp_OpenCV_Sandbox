#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "src/colorpicker.h"
#include <iostream>

using namespace std;

int hmin = 0, smin = 90, vmin = 153;
int hmax = 19, smax = 255, vmax = 255;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == cv::EVENT_LBUTTONDOWN )
     {
          Colorpicker* pick = (Colorpicker*)userdata;
          //pick->setPoint(x, y);
     }
}



int main()
{
	cv::Mat image = cv::imread("images/kabelki.jpg"); 
    cv::Mat img, mask;
    cv::resize(image, image, cv::Size(500, 500));
    cv::cvtColor(image, img, cv::COLOR_BGR2HSV);
    Colorpicker pick(img);
    cv::Point p;
    cv::Scalar color;

    cv::namedWindow("TrackBars", 1);
    cv::createTrackbar("Hue min", "TrackBars", &hmin, 179);
    cv::createTrackbar("Hue max", "TrackBars", &hmax, 179);
    cv::createTrackbar("Saturation min", "TrackBars", &smin, 255);
    cv::createTrackbar("Saturation max", "TrackBars", &smax, 255);
    cv::createTrackbar("Vue min", "TrackBars", &vmin, 255);
    cv::createTrackbar("Vue max", "TrackBars", &vmax, 255);

    cv::namedWindow("SOURCE", 2);
    cv::setMouseCallback("SOURCE", CallBackFunc, &pick);
    for(;;)
    {
    cv::Scalar lower(hmin, smin, vmin);
    cv::Scalar upper(hmax, smax, vmax);

    cv::cvtColor(image, img, cv::COLOR_BGR2HSV);
    cv::inRange(img, lower, upper, mask);

	cv::imshow("SOURCE", image);
    cv::imshow("MASK", mask);
	cv::waitKey(1);
    }
	return(0);
}

