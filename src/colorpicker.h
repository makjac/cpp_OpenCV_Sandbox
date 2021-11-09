#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

class Colorpicker
{
public:
    Colorpicker(cv::Mat image)
    {
        img=image;
        h = 0;
        s = 0;
        v = 0;
    }
    void setPoint(int x, int y)
    {
    point.x = x;
    point.y = y;
    h=(int)img.at<cv::Vec3b>(y, x)[0];
    s=(int)img.at<cv::Vec3b>(y, x)[1];
    v=(int)img.at<cv::Vec3b>(y, x)[2];
    std::cout << h << " " << s << " " << v << std::endl;
    }

    void setImage(cv::Mat image)
    {
        img = image;
    }

    int getH(bool max)
    {
        if(max) 
            if(h+5>179)
                return(179);
            else
                return(h+5);
        else
            if(h-5<0)
                return(0);
            else
                return(h-5);
    }
    int getS(bool max)
    {
        if(max) 
            if(s+50>255)
                return(255);
            else
                return(s+50);
        else
            if(s-50<0)
                return(0);
            else
                return(s-50);
    }
    int getV(bool max)
    {
        if(max) 
            if(v+50>255)
                return(255);
            else
                return(v+50);
        else
            if(v-50<0)
                return(0);
            else
                return(v-50);
    }

private:
cv::Mat img;
cv::Point point;
int h, s, v;
};