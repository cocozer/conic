#pragma once
#include <iostream>
#include <Eigen/Dense>

#include "Point2D.hpp"
#include "Constants.hpp"

class Point2D; // Déclaration avancée de la classe Point2D pour pouvoir créer des droites à partir de deux points

namespace geomproj { 
class Line2D
{
    private :
    double m_a;
    double m_b;
    double m_c;

    public :
    // Constructeurs et Destructeur
    Line2D(); // Constructeur par défaut

    Line2D(const double &a, const double &b, const double &c); // Constructeur de Line2D à partir de a, b et c

    Line2D(const Point2D &x1, const Point2D &x2); // Constructeur de Line2D à partir de 2 Point2D

    Line2D(const Line2D &l); // Constructeur par copie

    ~Line2D() = default; // Appelle les destructeurs par défaut de a, b et c

    //Getters et Setters en Inline pour améliorer la lisibilité du code
    inline void set_a(const double &a) { m_a = a; }
    inline void set_b(const double &b) { m_b = b; }
    inline void set_c(const double &c) { m_c = c; }
    inline double get_a() const { return m_a; }
    inline double get_b() const { return m_b; }
    inline double get_c() const { return m_c; }

    Eigen::Vector3d get_vector() const; // Renvoie le vecteur de la droite
    inline Eigen::RowVector3d get_transposed() const { return get_vector().transpose();} // Renvoie le vecteur transposé de la droite

    // Méthodes
    bool has(const Point2D &point) const; // Renvoie vrai si le point est sur la droite

    void display() const; // Affiche les informations de la droite
    
    //Surcharge des opérateurs
    Line2D& operator=(const Line2D &line);
};
}