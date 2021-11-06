#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/bgsegm.hpp>


int main()
{
    std::string path = "video/street.mp4";
    cv::VideoCapture capture;
    cv::Mat frame, fgmask;

    capture = cv::VideoCapture(path);

    if(!capture.isOpened())
        throw "Error when reading steam_avi";

    
    cv::Ptr<cv::BackgroundSubtractor> mog = cv::bgsegm::createBackgroundSubtractorMOG();

    for(;;)
    {
        capture >> frame;
        mog->apply(frame, fgmask);
        cv::imshow("SOURCE", frame);
        cv::imshow("MOG", fgmask);
        cv::waitKey(20);
    }


    cv::waitKey(0);
    return(0);
}