#include "Random.hpp"

namespace randgen { 

    int increment = 0; // L'incrément en variable globale permet de générer des nombres aléatoires et différents même si le programme s'execute en un instant

    double intGenerator(int min, int max){
        increment++; // A chaque génération aléatoire, l'incrément augmente
        // Selection de la graine avec le temps à l'instant présent + l'incrément
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count()+increment; 
        // Selection du générateur à partir de la graine
        std::mt19937 generator(seed);
        // On définit la distribution à partir des paramètres de la fonction
        std::uniform_int_distribution<int> distribution(min, max);
        // On génère et renvoie le nombre aléatoire
        return distribution(generator);
    }


    Point2P point2PGenerator(){
        return Point2P(intGenerator(1, 100), intGenerator(1, 100), intGenerator(1, 100)); // Appel du constructeur de Point2P à partir de 3 points aléatoires
    }


    std::vector<Point2P> pointsVectorGenerator(int nbPoints) {
        std::vector<Point2P> points;

        for (int i = 0; i < nbPoints; i++) {
            // Génère un point aléatoirement
            Point2P randomPoint = point2PGenerator();
            // Ajoute le point généré au vecteur points
            points.push_back(randomPoint);
        }

        return points;
    }

}