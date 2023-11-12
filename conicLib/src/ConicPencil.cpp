#include <iostream>


#include "ConicPencil.hpp"

namespace conic {
    ConicPencil::ConicPencil(const Conic &c1, const Conic &c2) 
    : m_conic1(c1), m_conic2(c2)
    {

    }

    ConicPencil::ConicPencil(const ConicPencil &cp)
    : m_conic1(cp.m_conic1), m_conic2(cp.m_conic2)
    {
        
    }

    Conic ConicPencil::get_conic(const float &var) {
        // AJOUTER ASSERT POUR VERIFIER SI VAR EST ENTRE 0 ET PI ----------------------------------------------------------------------
        
        Eigen::MatrixXd C = cos(var) * get_c1().matrix() + sin(var) * get_c2().matrix(); // Calcul de C(t), une conique de paramètre t du faisceau de coniques
        return Conic(C); // On retourne un constructeur de conique à partir de la matrice C
    }
}