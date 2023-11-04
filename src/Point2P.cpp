#include <iostream>


#include "Point2P.hpp"

Point2P::Point2P(const double x, const double y, const double w) 
: m_x(x), m_y(y), m_w(w)
{}

Point2P::Point2P(const double x, const double y) 
: m_x(x), m_y(y), m_w(1) // Le point est créé à partir de coordonnées Euclidiennes, w=1
{}

Point2P::Point2P(const Line2P l1, const Line2P l2) 
{
    // Ajouter code de constructeur de Point2P à partir de 2 droites (Line2P) -------------------------------------------------------------------

    Eigen::VectorXd d1(l1.get_a(), l1.get_b(), l1.get_c());   // création de 2 vecteurs contenant les coordonées a b c des droites
    Eigen::VectorXd d2(l2.get_a(), l2.get_b(), l2.get_c());
    Eigen::VectorXd prodVec = d1.cross(d2);    // produit vectoriel pour calculer les coordonnées du point

    // m_x() = prodVec(0);  // on assigne le resultat aux coordonnées du point (je connais pas la syntaxe)
    // m_y() = prodVec(1);
    // m_w() = prodVec(2);
   
}

Point2P::Point2P(const Point2P &point) 
: m_x(point.m_x), m_y(point.m_y), m_w(point.m_w)
{}

void Point2P::display() const {
    std::cout << "Informations du point :" << std::endl;
	std::cout << "x = " << get_x() << std::endl;
    std::cout << "y = " << get_y() << std::endl;
    std::cout << "w = " << get_w() << std::endl;
}