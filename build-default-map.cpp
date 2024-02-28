//
// Created by sacha on 27/02/24.
//
// Build default map with a middle square obstacle
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
    // Create a 100x100 matrix filled with white
    cv::Mat image(102, 102, CV_8UC1, cv::Scalar(255));

    // Create a black frame around the white background
    int frameThickness = 1; // Thickness of the frame
    cv::rectangle(image, cv::Point(0, 0), cv::Point(image.cols - 1, image.rows - 1), cv::Scalar(0), frameThickness);
    cv::rectangle(image, cv::Point(37, 37), cv::Point(64, 64), cv::Scalar(0), -1);

    // Save the image
    std::string filename = "map.pgm";
    cv::imwrite(filename, image);

    std::cout << "Image saved as " << filename << std::endl;

    return 0;
}