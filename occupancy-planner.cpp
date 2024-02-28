//
// Created by sacha on 27/02/24.
//
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "include/UndirectedGraph.h"

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: occupancy-planner.out <PGM>\n");
        return -1;
    }
    Mat map;
    map = imread(argv[1], IMREAD_UNCHANGED);
    if ( !map.data )
    {
        printf("No map data \n");
        return -1;
    }

    UndirectedGraph graph;

    // Add nodes for free space
    for(int i=0; i < map.rows; i++)
        for(int j=0; j < map.cols; j++) {
            auto pixelValue = static_cast<double> (map.at<uchar>(i, j));
            double occ = 1 - pixelValue/255;
            if (occ < .5)
                graph.addNode(i, j);
        }
    cout << graph.size() << "\n";

    // Add edges
    for (int i = 0; i < map.rows; i++)
        for (int j = 0; j < map.cols; j++) {
            Coord nodeFrom{i, j};
            if (!graph.hasNode(nodeFrom)) // We should iterate directly over nodes
                continue;
            vector<Coord> coords;
            coords.push_back(Coord{i + 1, j}); // North
            coords.push_back(Coord{i, j + 1}); // East
            coords.push_back(Coord{i - 1, j}); // South
            coords.push_back(Coord{i, j - 1}); // West
            if (true) {
                coords.push_back(Coord{i + 1, j + 1}); // North East
                coords.push_back(Coord{i - 1, j + 1}); // South East
                coords.push_back(Coord{i - 1, j - 1}); // South West
                coords.push_back(Coord{i + 1, j - 1}); // North East
            }
            for (const auto &nodeTo: coords)
                if (graph.hasNode(nodeTo))
                    graph.addEdge(nodeFrom, nodeTo);
        }

    auto path = graph.aStar(1, 1, 100, 100, [] (Coord a, Coord b) {return 0;});
    cout << path.size();


    // Create an empty 3-channel (RGB) map
    cv::Mat rgbImage(map.size(), CV_8UC3);

    // Convert grayscale to RGB
    cv::cvtColor(map, rgbImage, cv::COLOR_GRAY2RGB);


    // Visited
    for (const auto& [coord, node]: graph)
        if (node.fScore < numeric_limits<double>::infinity())
            rgbImage.at<cv::Vec3b>(coord.x, coord.y) = cv::Vec3b(238, 238, 175);

    // Path
    for (const auto& coord: path)
        rgbImage.at<cv::Vec3b>(coord.x, coord.y) = cv::Vec3b(0, 0, 255);


    std::string filename = "map_dijkstra.png";
    cv::imwrite(filename, rgbImage);
    return 0;
}
