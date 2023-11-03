#pragma once
#include <random>
#include <chrono>
#include <Eigen/Dense>

#include "Point2P.hpp"


namespace randgen { 
    double intGenerator(int min, int max); // Génération aléatoire d'un entier
    Point2P point2PGenerator(); // Génération aléatoire d'un point dans la géométrie projective
    Point2P idealPoint2PGenerator(); // Génération aléatoire d'un point idéal dans la géométrie projective
    std::vector<Point2P> pointsVectorGenerator(int nbPoints);  // Génération aléatoire de n points rangés dans un vecteur
}