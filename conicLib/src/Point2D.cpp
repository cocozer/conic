#include <iostream>


#include "Point2D.hpp"

namespace geomproj { 
Point2D::Point2D(const double &x, const double &y, const double &w) 
: m_x(x), m_y(y), m_w(w)
{}

Point2D::Point2D(const double &x, const double &y) 
: m_x(x), m_y(y), m_w(1) // Le point est créé à partir de coordonnées Euclidiennes, w=1
{}

Point2D::Point2D(const Line2D &l1, const Line2D &l2) 
{
    Eigen::Vector3d d1; // Création du vecteur de la droite d1
    d1 << l1.get_a(), l1.get_b(), l1.get_c();  // Assignation de a, b et c
    Eigen::Vector3d d2; // Création du vecteur de la droite d1
    d2 << l2.get_a(), l2.get_b(), l2.get_c();  // Assignation de a, b et c
    Eigen::Vector3d prodVec = d1.cross(d2);    // produit vectoriel des deux vecteurs pour calculer les coordonnées du point

    set_x(prodVec(0));  // on assigne le resultat aux coordonnées du point (je connais pas la syntaxe)
    set_y(prodVec(1));
    set_w(prodVec(2));
   
}

Point2D::Point2D(const Point2D &point) 
: m_x(point.m_x), m_y(point.m_y), m_w(point.m_w)
{}

void Point2D::display() const {
    std::cout << "Informations du point :" << std::endl;
	std::cout << "x = " << get_x() << std::endl;
    std::cout << "y = " << get_y() << std::endl;
    std::cout << "w = " << get_w() << std::endl;
}
}