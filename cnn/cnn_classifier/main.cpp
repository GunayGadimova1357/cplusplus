// #include <opencv2/opencv.hpp>
//
// int main() {
//
//     cv::Mat image = cv::imread("/Users/xalida/Documents/Projects/cnn_classifier/cat.jpg");
//
//
//     if (image.empty()) {
//         std::cerr << "error!" << std::endl;
//         return -1;
//     }
//
//
//     cv::Mat gray;
//     cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//
//     cv::Mat blurred;
//     cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 1.5);
//
//
//     cv::Mat edges;
//     cv::Canny(blurred, edges, 100, 200);
//
//
//     cv::imshow("Image", image);
//     cv::imshow("Edges", edges);
//
//
//     cv::waitKey(0);
//
//     return 0;
// }

#include <opencv2/opencv.hpp>
#include <iostream>

#include <opencv2/opencv.hpp>

int main() {

    cv::Mat image = cv::imread("/Users/xalida/Documents/Projects/cnn_classifier/da.jpg");


    if (image.empty()) {
        std::cerr << "error!" << std::endl;
        return -1;
    }


    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);


    cv::Mat blurred;
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 1.5);


    cv::Mat edges;
    cv::Canny(blurred, edges, 100, 200);


    cv::imshow("Image", image);
    cv::imshow("Edges", edges);


    cv::waitKey(0);

    return 0;
}
