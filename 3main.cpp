#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/bgsegm.hpp>


int main()
{
    std::string path = "video/street.mp4";
    cv::VideoCapture capture;
    cv::Mat frame, fgmask;

    capture = cv::VideoCapture(0);

    if(!capture.isOpened())
        throw "Error when reading steam_avi";

    
    cv::Ptr<cv::BackgroundSubtractor> mog = cv::bgsegm::createBackgroundSubtractorMOG();

    for(;;)
    {
        capture >> frame;
        cv::imshow("SOURCE", frame);
        cv::GaussianBlur(frame, frame, cv::Size(3,3), 1, 1);
        mog->apply(frame, fgmask);
        cv::imshow("MOG", fgmask);
        cv::imshow("CANNY", frame);
        cv::waitKey(1);
    }


    cv::waitKey(0);
    return(0);
}