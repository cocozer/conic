#include <iostream>


#include "ConicPencil.hpp"

namespace conic {

    ConicPencil::ConicPencil() 
    : m_conic1(), m_conic2()
    {

    }

    ConicPencil::ConicPencil(const Conic &c1, const Conic &c2) 
    : m_conic1(c1), m_conic2(c2)
    {

    }

    ConicPencil::ConicPencil(const ConicPencil &cp)
    : m_conic1(cp.m_conic1), m_conic2(cp.m_conic2)
    {
        
    }

    Conic ConicPencil::get_conic(const float &var) {
        if (var < 0.0f || var > M_PI) { // Si la valeur aléatoire n'est pas comprise entre 0 et PI, on lance une exception.
            throw std::invalid_argument("La valeur de var doit être comprise entre 0 et PI.");
        }
        
        Eigen::MatrixXd C = cos(var) * get_c1().get_matrix() + sin(var) * get_c2().get_matrix(); // Calcul de C(var), une conique de paramètre var du faisceau de coniques
        return Conic(C); // On retourne un constructeur de conique à partir de la matrice C
    }
}