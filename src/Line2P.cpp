#include <iostream>


#include "Line2P.hpp"

Line2P::Line2P(const double a, const double b, const double c)
: m_a(a), m_b(b), m_c(c)
{}

Line2P::Line2P(const Point2P x1, const Point2P x2) 
{
    // Ajouter code de constructeur de Line2P à partir de 2 points -----------------------------------------------------------------------------

    Eigen::VectorXd p1(x1.get_x(), x1.get_y(), x1.get_w());   // création de 2 vecteurs contenant les coordonées x y w des points
    Eigen::VectorXd p2(x2.get_x(), x2.get_y(), x2.get_w());
    Eigen::VectorXd prodVec = p1.cross(p2);    // produit vectoriel pour calculer les coordonnées de la droite

    // m_a() = prodVec(0);  // on assigne le resultat aux coordonnées de la droite (je connais pas la syntaxe)
    // m_b() = prodVec(1);
    // m_c() = prodVec(2);
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