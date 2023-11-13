#include <iostream>


#include "Conic.hpp"

namespace conic {
Conic::Conic() 
: m_a(0.0), m_b(0.0), m_c(0.0), m_d(0.0), m_e(0.0), m_f(0.0) 
{}

Conic::Conic(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f)
: m_a(a), m_b(b), m_c(c), m_d(d), m_e(e), m_f(f)
{}

Conic::Conic(const Eigen::MatrixXd &A){

    // Vérification de la taille de la matrice
    if (A.rows() != 3 || A.cols() != 3) {
        throw std::invalid_argument("La matrice A doit être de taille 3x3 pour créer une conique.");
    }
    
    // En suivant le modèle de matrice d'une conique, on attribue les valeurs a, b, c, d, e et f à la conique
    set_a(A(0, 0));
    set_b(A(0, 1)*2);
    set_c(A(1, 1));
    set_d(A(0, 2)*2);
    set_e(A(1, 2)*2);
    set_f(A(2, 2));
} 


Conic::Conic(const Conic &conic) 
: m_a(conic.m_a), m_b(conic.m_b), m_c(conic.m_c), m_d(conic.m_d), m_e(conic.m_e), m_f(conic.m_f)
{}

void Conic::display() const {
    std::cout << "Informations de la conique :" << std::endl;
	std::cout << "a = " << get_a() << std::endl;
    std::cout << "b = " << get_b() << std::endl;
    std::cout << "c = " << get_c() << std::endl;
    std::cout << "d = " << get_d() << std::endl;
    std::cout << "e = " << get_e() << std::endl;
    std::cout << "f = " << get_f() << std::endl;
}

Eigen::MatrixXd Conic::get_matrix() const {
    Eigen::MatrixXd C(3,3); // Initialisation d'une matrice 3 3 puis entrée des valeurs dans la matrice
    C(0,0) = get_a();
    C(0,1) = get_b()/2;
    C(0,2) = get_d()/2;
    C(1,0) = get_b()/2;
    C(1,1) = get_c();
    C(1,2) = get_e()/2;
    C(2,0) = get_d()/2;
    C(2,1) = get_e()/2;
    C(2,2) = get_f();

    return C; // Renvoi de la matrice de la conique
}

bool Conic::has(const geomproj::Point2D &point) const {
    return (point.get_transposed()*get_matrix()*point.get_vector()==0);
}
bool Conic::has(const geomproj::Line2D &line) const {
    return (line.get_transposed()*get_matrix()*line.get_vector()==0);
}

// Surcharge des opérateurs 

Conic& Conic::operator=(const Conic &conic) {
    if (this != &conic) {
        m_a = conic.m_a;
        m_b = conic.m_b;
        m_c = conic.m_c;
        m_d = conic.m_d;
        m_e = conic.m_e;
        m_f = conic.m_f;
    }
    return *this;
}

}