#pragma once
#include <random>
#include <chrono>
#include <Eigen/Dense>

#include "Point2D.hpp"
#include "Conic.hpp"
#include "ConicPencil.hpp"


namespace randgen { 
    extern int increment; // Déclaration de la variable globale increment en externe pour l'utiliser dans la fonction template

    template<typename T> // Fonction template qui permet de générer un nombre aléatoire à virgule
    T numberGenerator(T min, T max) {
        increment++;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count() + increment;
        std::mt19937 generator(seed);
        std::uniform_real_distribution<float> distribution(min, max);
        return distribution(generator);
    }

    int numberGenerator(int min, int max); // Surcharge de la fonction numberGenerator pour générer un entier si les paramètres min et max sont des entiers
    geomproj::Point2D point2DGenerator(); // Génération aléatoire d'un point dans la géométrie projective
    geomproj::Point2D idealPoint2DGenerator(); // Génération aléatoire d'un point idéal dans la géométrie projective
    std::vector<geomproj::Point2D> pointsVectorGenerator(int nbPoints);  // Génération aléatoire de n points rangés dans un vecteur

    conic::Conic conicFromConicPencilGenerator(conic::ConicPencil &myConicPencil); // Génération aléatoire d'une conique du faisceau myConicPencil avec un paramètre aléatoire 
    std::vector<conic::Conic> conicsFromConicPencilGenerator(conic::ConicPencil &myConicPencil, int numConics); // Génération aléatoire de n conics du faisceau
}