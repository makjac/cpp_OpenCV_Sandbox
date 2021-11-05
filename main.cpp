#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

int main()
{
	std::string path = "images/karty.jpg";
    float w=250, h=350;
    cv::Mat matx, imgWarp1, imgWarp2;
    cv::Mat image=cv::imread(path);

    cv::Point2f rec1[4] = { {906, 960}, {1210, 640}, {1818, 982}, {1530, 1412} };
    cv::Point2f dst1[4] = { {0.0f, 0.0f}, {w, 0.0f}, {w, h}, {0.0f, h} };
    matx = cv::getPerspectiveTransform(rec1, dst1);
    cv::warpPerspective(image, imgWarp1, matx, cv::Point(w, h));

    cv::Point2f rec2[4] = { {188, 1238}, {502, 734}, {874, 816}, {610, 1368} };
    cv::Point2f dst2[4] = { {0.0f, 0.0f}, {h+20, 0.0f}, {h+20, w}, {0.0f, w} };
    matx = cv::getPerspectiveTransform(rec2, dst2);
    cv::warpPerspective(image, imgWarp2, matx, cv::Point(h+20, w));

    cv::imshow("SOURCE", image);
    cv::imshow("WARP 1", imgWarp1);
    cv::imshow("WARP 2", imgWarp2);

    cv::waitKey(0);
    return(0);
}