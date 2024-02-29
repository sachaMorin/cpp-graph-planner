//
// Created by sacha on 28/02/24.
//

#ifndef CPP_PLANNER_OCCUPANCYGRAPH_H
#define CPP_PLANNER_OCCUPANCYGRAPH_H

#include "string"
#include "opencv2/opencv.hpp"
#include "GridGraph.h"


class OccupancyGraph : public GridGraph {
public:
    explicit OccupancyGraph(const string &path, bool eightWayConn = true);
    void saveImage(const string &filename);

private:
    cv::Mat map;
    void createNodes() override;
    cv::Mat loadMap(const string& path);

};


#endif //CPP_PLANNER_OCCUPANCYGRAPH_H
