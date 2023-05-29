#include "opencv2/opencv.hpp"

auto main() -> int
{
    // load an image using the compiler definition for the image path:
    cv::Mat image = cv::imread(std::string(IMGPATH) + "/desk_contours.jpg", 0);

    // calculate the edge image
    cv::Mat edges;  // = cv::Mat(image.size(), CV_8UC1);
    cv::Canny(image, edges, 100, 255);

    // write text on the matrix:
    cv::putText(edges, "Canny Edges", cv::Point(15, 70), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(255, 255, 255), 4);

    cv::imwrite(std::string(OUTPATH) + "/opencv_canny.jpg", edges);

    return 0;
}