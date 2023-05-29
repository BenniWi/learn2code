#include "opencv2/opencv.hpp"

auto main() -> int
{
    // initialize a 120X350 matrix with 3 channels of black pixels:
    cv::Mat output = cv::Mat::zeros(120, 350, CV_8UC3);

    // write text on the matrix:
    cv::putText(output, "Hello World :)", cv::Point(15, 70), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(0, 255, 0), 4);

    // write the resulting image to file
    cv::imwrite(std::string(OUTPATH) + "/opencv_hello.jpg", output);

    return 0;
}