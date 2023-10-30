#pragma once
#include <random>
#include <chrono>
#include <Eigen/Dense>

#include "Point2P.hpp"


namespace random { 
    double intGenerator(int min, int max);
    Point2P point2PGenerator();
    std::vector<Point2P> pointsVectorGenerator(int nbPoints);
}