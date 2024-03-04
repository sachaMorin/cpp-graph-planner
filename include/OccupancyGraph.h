//
// Created by sacha on 28/02/24.
//

#ifndef CPP_PLANNER_OCCUPANCYGRAPH_H
#define CPP_PLANNER_OCCUPANCYGRAPH_H

#include <string>
#include <opencv2/opencv.hpp>
#include "GridGraph.h"


// Build a graph from an occupancy map in a pgm file
class OccupancyGraph : public GridGraph {
public:
    explicit OccupancyGraph(const std::string &path, bool eightWayConn = true);

    void saveImage(const std::string &filename);

private:
    cv::Mat map;

    void createNodes() override;

    cv::Mat loadMap(const std::string &path);

};


#endif //CPP_PLANNER_OCCUPANCYGRAPH_H
