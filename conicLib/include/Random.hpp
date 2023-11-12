#pragma once
#include <random>
#include <chrono>
#include <Eigen/Dense>

#include "Point2D.hpp"


namespace randgen { 
    double intGenerator(int min, int max); // Génération aléatoire d'un entier
    float floatGenerator(float min, float max); // Génération aléatoire d'un float
    geomproj::Point2D point2DGenerator(); // Génération aléatoire d'un point dans la géométrie projective
    geomproj::Point2D idealPoint2DGenerator(); // Génération aléatoire d'un point idéal dans la géométrie projective
    std::vector<geomproj::Point2D> pointsVectorGenerator(int nbPoints);  // Génération aléatoire de n points rangés dans un vecteur
}