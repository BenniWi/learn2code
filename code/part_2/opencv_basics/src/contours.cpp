#include <vector>

#include "opencv2/opencv.hpp"

auto main() -> int
{
    // load an image using the compiler definition for the image path:
    cv::Mat image = cv::imread(std::string(IMGPATH) + "/desk_contours_3.jpg");

    // convert the image to grayscale format
    cv::Mat image_gray;
    cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);

    // calculate the edge image
    cv::Mat edges;  // = cv::Mat(image.size(), CV_8UC1);
    cv::Canny(image_gray, edges, 180, 300);

    // detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(edges, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
    // draw contours on the original image
    cv::drawContours(image, contours, -1, cv::Scalar(0, 255, 0), 2);

    // write text on the image
    cv::putText(image, "Contours", cv::Point(15, 70), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(0, 255, 0), 4);
    // write image with contours to file
    cv::imwrite(std::string(OUTPATH) + "/opencv_contours.jpg", image);

    // write text on the edge image
    cv::putText(edges, "Edges", cv::Point(15, 70), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(255, 255, 255), 4);
    // write image with edges to file
    cv::imwrite(std::string(OUTPATH) + "/opencv_contours_edges.jpg", edges);

    return 0;
}