#include <iostream>


#include "Line2D.hpp"

namespace geomproj { 

Line2D::Line2D()
: m_a(0), m_b(0), m_c(0)
{}

Line2D::Line2D(const double &a, const double &b, const double &c)
: m_a(a), m_b(b), m_c(c)
{}

Line2D::Line2D(const Point2D &x1, const Point2D &x2) 
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

Line2D::Line2D(const Line2D &line) 
: m_a(line.m_a), m_b(line.m_b), m_c(line.m_c)
{}

Eigen::Vector3d Line2D::get_vector() const {
    Eigen::Vector3d v; // Initialisation d'un vecteur3 puis assigiation des valeurs
    v(0) = get_a();
    v(1) = get_b();
    v(2) = get_c();

    return v; // Renvoi du vecteur de la droite
}

bool Line2D::has(const Point2D &point) const {
    return (std::abs(get_transposed()*point.get_vector())<epsilon);
}

void Line2D::display() const {
    std::cout << "Informations de la droite :" << std::endl;
	std::cout << "a = " << get_a() << std::endl;
    std::cout << "b = " << get_b() << std::endl;
    std::cout << "c = " << get_c() << std::endl;
}

Line2D& Line2D::operator=(const Line2D &line) {
        if (this != &line) {
            m_a = line.m_a;
            m_b = line.m_b;
            m_c = line.m_c;
        }
        return *this;
    }

}