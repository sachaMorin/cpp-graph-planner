//
// Created by sacha on 27/02/24.
//
// Build default map with a middle square obstacle
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: ./default-maps <OUTPUT DIR> >\n");
        return -1;
    }
    std::string path = argv[1];

    // Create a 100x100 matrix filled with white
    cv::Mat image(102, 102, CV_8UC1, cv::Scalar(255));

    // Create a black frame around the white background
    int frameThickness = 1; // Thickness of the frame
    cv::rectangle(image, cv::Point(0, 0), cv::Point(image.cols - 1, image.rows - 1), cv::Scalar(0), frameThickness);

    std::string filename_empty = path + "/map_empty.pgm";
    cv::imwrite(filename_empty, image);
    std::cout << "Image saved as " << filename_empty << std::endl;


    // Add Obstacle
    cv::rectangle(image, cv::Point(37, 37), cv::Point(64, 64), cv::Scalar(0), -1);

    std::string filename = path + "/map.pgm";
    cv::imwrite(filename, image);
    std::cout << "Image saved as " << filename << std::endl;

    return 0;
}