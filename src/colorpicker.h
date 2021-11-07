#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

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
    void setPoint(int x, int y);

private:
cv::Mat img;
cv::Point point;
int h, s, v;
};