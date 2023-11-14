#include <iostream>


#include "ConicPencil.hpp"

namespace conic {

    ConicPencil::ConicPencil() 
    : m_conic1(), m_conic2()
    {

    }

    ConicPencil::ConicPencil(Conic c1, Conic c2) 
    {
        // On norme c1 et c2 avant de créer le faisceau de coniques
        double normOfc1 = sqrt(pow(c1.get_a(), 2) + pow(c1.get_b(), 2) + pow(c1.get_c(), 2) + pow(c1.get_d(), 2) + pow(c1.get_e(), 2) + pow(c1.get_f(), 2));
        
        double normOfc2 = sqrt(pow(c2.get_a(), 2) + pow(c2.get_b(), 2) + pow(c2.get_c(), 2) + pow(c2.get_d(), 2) + pow(c2.get_e(), 2) + pow(c2.get_f(), 2));
        
        c1.set_a(c1.get_a()/normOfc1);
        c1.set_b(c1.get_b()/normOfc1);
        c1.set_c(c1.get_c()/normOfc1);
        c1.set_d(c1.get_d()/normOfc1);
        c1.set_e(c1.get_e()/normOfc1);
        c1.set_f(c1.get_f()/normOfc1);

        c2.set_a(c2.get_a()/normOfc2);
        c2.set_b(c2.get_b()/normOfc2);
        c2.set_c(c2.get_c()/normOfc2);
        c2.set_d(c2.get_d()/normOfc2);
        c2.set_e(c2.get_e()/normOfc2);
        c2.set_f(c2.get_f()/normOfc2);

        set_c1(c1);
        set_c2(c2);
    }

    ConicPencil::ConicPencil(const ConicPencil &cp)
    : m_conic1(cp.m_conic1), m_conic2(cp.m_conic2)
    {
        
    }

    Conic ConicPencil::get_conic(const float &var) {
        if (var < 0.0f || var > M_PI) { // Si la valeur aléatoire n'est pas comprise entre 0 et PI, on lance une exception.
            throw std::invalid_argument("La valeur de var doit être comprise entre 0 et PI. La valeur renseignée était : "+ std::to_string(var));
        }
        
        Eigen::MatrixXd C = cos(var) * get_c1().get_matrix() + sin(var) * get_c2().get_matrix(); // Calcul de C(var), une conique de paramètre var du faisceau de coniques
        return Conic(C); // On retourne un constructeur de conique à partir de la matrice C
    }

    ConicPencil& ConicPencil::operator=(const ConicPencil &cp) {
        if (this != &cp) {
            m_conic1 = cp.m_conic1;
            m_conic2 = cp.m_conic2;
        }
        return *this;
    }
}