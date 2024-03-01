//
// Created by sacha on 28/02/24.
//

#include <opencv2/opencv.hpp>
#include "OccupancyGraph.h"

using namespace std;
using namespace cv;

OccupancyGraph::OccupancyGraph(const string &path, const bool eightWayConn) : map(loadMap(path))  {
    width = map.rows;
    height = map.cols;
    eightWay = eightWayConn;


    createNodes();
    createEdges();
}

void OccupancyGraph::createNodes() {
    // Only add nodes for free space
    for(int i=0; i < width; i++)
        for(int j=0; j < height; j++) {
            auto pixelValue = static_cast<double> (map.at<uchar>(i, j));
            double occ = 1 - pixelValue/255;
            if (occ < .01)
                this->addNode(i, j);
        }
}

void OccupancyGraph::saveImage(const string &filename) {
    // Create an empty 3-channel (RGB) map
    Mat rgbImage(map.size(), CV_8UC3);

    // Convert grayscale to RGB
    cvtColor(map, rgbImage, COLOR_GRAY2RGB);


    // Visited
    for (const auto& [coord, node]: *this)
        if (node.fScore < numeric_limits<double>::infinity())
            rgbImage.at<Vec3b>(coord.x, coord.y) = Vec3b(238, 238, 175);

    // Path
    for (const auto& coord: aStarPath.path)
        rgbImage.at<Vec3b>(coord.x, coord.y) = Vec3b(0, 0, 255);


    imwrite(filename, rgbImage);
    cout << "Image saved as " << filename << endl;
}

cv::Mat OccupancyGraph::loadMap(const string& path) {
    Mat currentMap =  imread(path, IMREAD_UNCHANGED);
    if(!currentMap.data)
        throw GraphException("Map is empty! Is this the right path?");

    return currentMap;
}
