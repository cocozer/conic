#include "Random.hpp"

namespace randgen { 

    int increment = 0;

    int numberGenerator(int min, int max){
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

    


    geomproj::Point2D point2DGenerator(){
        return geomproj::Point2D(numberGenerator(-10, 10), numberGenerator(-6, 6)); // Appel du constructeur de Point2D à partir de 2 coordonnées aléatoires
    }

    geomproj::Point2D idealPoint2DGenerator(){
        return geomproj::Point2D(numberGenerator(-10, 10), numberGenerator(-6, 6), 0); // Appel du constructeur de Point2D à partir de 2 coordonnées aléatoires et 0 (infini)
    }


    std::vector<geomproj::Point2D> pointsVectorGenerator(int nbPoints) {
        std::vector<geomproj::Point2D> points;

        for (int i = 0; i < nbPoints; i++) {
            // Génère un point aléatoirement
            geomproj::Point2D randomPoint = point2DGenerator();
            // Ajoute le point généré au vecteur points
            points.push_back(randomPoint);
        }

        return points;
    }
    
    conic::Conic conicFromConicPencilGenerator(conic::ConicPencil& myConicPencil) {
    try {
        return myConicPencil.get_conic(randgen::numberGenerator(0.0f, static_cast<float>(M_PI)));
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la génération de la conique : " << e.what() << std::endl;
        return conic::Conic(); // renvoi d'une conique par défaut s'il y a une erreur
    }
}

}