#pragma once
#include <iostream>
#include <Eigen/Dense>

#include "Line2D.hpp"

class Line2D; // Déclaration avancée de la classe Line2D pour pouvoir créer des points à partir d'intersection de droites

namespace geomproj { 
class Point2D
{
    private :
    double m_x;
    double m_y;
    double m_w;

    public :
    // Constructeurs et Destructeur
    Point2D(); // Constructeur par défaut

    Point2D(const double &x, const double &y, const double &w); // Constructeur de Point2D à partir de coordonnées Homogènes

    Point2D(const double &x, const double &y); // Constructeur de Point2D à partir de coordonnées Euclidiennes

    Point2D(const Line2D &l1, const Line2D &l2); // Constructeur de Point2D à partir de l'intersection entre 2 Line2D

    Point2D(const Point2D &p); // Constructeur par copie

    ~Point2D() = default; // Appelle les destructeurs par défaut de x, y et w

    //Getters et Setters en Inline pour améliorer la lisibilité du code
    inline void set_x(const double &x) { m_x = x; }
    inline void set_y(const double &y) { m_y = y; }
    inline void set_w(const double &w) { m_w = w; }
    inline double get_x() const { return m_x; }
    inline double get_y() const { return m_y; }
    inline double get_w() const { return m_w; }

    // Méthodes
    void display() const; // Affiche les informations du point
    
};
}