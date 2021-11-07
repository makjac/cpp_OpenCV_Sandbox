#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/bgsegm.hpp>


int main()
{
    std::string path = "video/street.mp4";
    cv::VideoCapture capture;
    cv::Mat frame, fgmask;

    float img_data[9]={-1, -1, -1, -1, 9, -1, -1, -1, -1};
    cv::Mat kernel = cv::Mat(3, 3, CV_32F, img_data);

    capture = cv::VideoCapture(0);

    if(!capture.isOpened())
        throw "Error when reading steam_avi";

    
    //cv::Ptr<cv::BackgroundSubtractor> mog = cv::bgsegm::createBackgroundSubtractorMOG();
    //cv::Ptr<cv::BackgroundSubtractor> mog = cv::createBackgroundSubtractorMOG2(500, 16.0, false);
    cv::Ptr<cv::BackgroundSubtractor> mog = cv::createBackgroundSubtractorKNN(300, 1000.0, false);

    for(;;)
    {
        capture >> frame;
        cv::imshow("SOURCE", frame);
        //cv::filter2D(frame, frame, -1, kernel, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
        cv::GaussianBlur(frame, frame, cv::Size(5,5), 1, 1);
        mog->apply(frame, fgmask);
        cv::imshow("MOG", fgmask);
        //cv::imshow("CANNY", frame);
        cv::waitKey(10);
    }


    cv::waitKey(0);
    return(0);
}