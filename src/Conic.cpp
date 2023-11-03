#include <iostream>


#include "Conic.hpp"

Conic::Conic(const double a, const double b, const double c, const double d, const double e, const double f)
: m_a(a), m_b(b), m_c(c), m_d(d), m_e(e), m_f(f)
{}

Conic::Conic(const Point2P x1, const Point2P x2, const Point2P x3, const Point2P x4, const Point2P x5) 
{
    std::vector<Point2P> points = {x1, x2, x3, x4, x5}; // Création d'un vecteur de 5 points

    Eigen::MatrixXd A(5,6); // Initialisation de la matrice du système
    A.col(5).setOnes();         // Remplit la dernière colonne de 1

    // Boucle pour remplir toutes les lignes de la matrice A à partir du vecteur des 5 points
    for(size_t i = 0; i<5; i++) {
        A(i,0) = pow(points[i].get_x(),2);
        A(i,1) = points[i].get_x() * points[i].get_y();
        A(i,2) = pow(points[i].get_y(), 2);
        A(i,3) = points[i].get_x();
        A(i,4) = points[i].get_y();
    }
    
    
    // Calcul du noyau de A avec Eigen :
    Eigen::JacobiSVD < Eigen :: MatrixXd > svd (A , Eigen :: ComputeThinU | Eigen :: ComputeFullV );
    Eigen::VectorXd x = svd.matrixV().rightCols(1); // Vecteur x qui contient les paramètres a, b, c, d, e et f de la conique
    
    set_a(x(0));
    set_b(x(1));
    set_c(x(2));
    set_d(x(3));
    set_e(x(4));
    set_f(x(5));
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