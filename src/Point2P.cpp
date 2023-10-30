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