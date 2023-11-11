#include <iostream>


#include "Line2P.hpp"

Line2P::Line2P(const double a, const double b, const double c)
: m_a(a), m_b(b), m_c(c)
{}

Line2P::Line2P(const Point2P x1, const Point2P x2) 
{
    Eigen::Vector3d p1; // Création du vecteur de p1
    p1 << x1.get_x(), x1.get_y(), x1.get_w(); // Assignation de x y et w
    
    Eigen::Vector3d p2; // Création du vecteur de p2
    p2 << x2.get_x(), x2.get_y(), x2.get_w(); // Assignation de x y et w

    Eigen::VectorXd prodVec = p1.cross(p2);    // produit vectoriel pour calculer les coordonnées de la droite

    set_a(prodVec(0));  // on assigne le resultat aux coordonnées de la droite 
    set_b(prodVec(1));
    set_c(prodVec(2));
}

Line2P::Line2P(const Line2P &line) 
: m_a(line.m_a), m_b(line.m_b), m_c(line.m_c)
{}

void Line2P::display() const {
    std::cout << "Informations de la droite :" << std::endl;
	std::cout << "a = " << get_a() << std::endl;
    std::cout << "b = " << get_b() << std::endl;
    std::cout << "c = " << get_c() << std::endl;
}