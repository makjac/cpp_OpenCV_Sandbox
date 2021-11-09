#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>

int main()
{
    int choice=0;
    int yt=0, yb=0;
    std::string path = "video/street.mp4"; //path to movie file
    cv::VideoCapture capture;
    cv::Mat frame, subIm;
    cv::Mat lajka = cv::imread("images/lajka.jpg");
    cv::Rect region;
    capture = cv::VideoCapture(0);//path = play movie file, 0 = play camera

    if(!capture.isOpened())
        throw "ERROR when reading steam_avi";
    
    cv::CascadeClassifier faceCascade;
    faceCascade.load("haarcascades/haarcascade_frontalface_default.xml");

    if(faceCascade.empty())
        throw "ERROR when reading XML file";

    std::vector<cv::Rect> faces;

    cv::namedWindow("TRACKBARS");
    cv::createTrackbar("censor", "TRACKBARS", &choice, 4);

    for(;;)
    {
        capture >> frame;
        faceCascade.detectMultiScale(frame, faces, 1.1, 10);

        switch(choice)
        {
            case 1:
                for(int i=0; i<faces.size(); i++)
                    cv::rectangle(frame, faces[i].tl(), faces[i].br(), cv::Scalar(42, 104, 62), 3);
                break;
            case 2:
                for(int i=0; i<faces.size(); i++)
                {
                    region = cv::Rect(faces[i].tl(), faces[i].br());
                    cv::GaussianBlur(frame(region), frame(region), cv::Size(0, 0), 4);
                }
                break;
            case 3:
                for(int i=0; i<faces.size(); i++)
                {
                    yt = faces[i].tl().y + (faces[i].height * 2/8);
                    yb = faces[i].br().y - (faces[i].height * 4/8);
                    cv::rectangle(frame, cv::Rect(faces[i].tl().x, yt, faces[i].width, yb-yt), cv::Scalar(0, 0, 0), cv::FILLED);
                }
                break;
            case 4:
                for(int i=0; i<faces.size(); i++)
                {
                    region = cv::Rect(faces[i].tl(), faces[i].br());
                    cv::resize(lajka, subIm, cv::Size(faces[i].br().x - faces[i].tl().x, faces[i].br().y - faces[i].tl().y));
                    subIm.copyTo(frame(cv::Rect(faces[i].tl().x, faces[i].tl().y, subIm.cols, subIm.rows)));
                }
                break;
            default:
                break;
        }
        cv::imshow("SOURCE", frame);
        cv::waitKey(20);
    }
    
    return(0);
}