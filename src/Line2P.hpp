#pragma once
#include <iostream>
#include <Eigen/Dense>

#include "Point2P.hpp"

class Point2P; // Déclaration avancée de la classe Point2P pour pouvoir créer des droites à partir de deux points

class Line2P
{
    private :
    double m_a;
    double m_b;
    double m_c;

    public :
    // Constructeurs et Destructeur
    Line2P(const double a, const double b, const double c); // Constructeur de Line2P à partir de a, b et c

    Line2P(const Point2P x1, const Point2P x2); // Constructeur de Line2P à partir de 2 Point2P

    Line2P(const Line2P &l); // Constructeur par copie

    ~Line2P() = default; // Appelle les destructeurs par défaut de a, b et c

    //Getters et Setters en Inline pour améliorer la lisibilité du code
    inline void set_a(const double &a) { m_a = a; }
    inline void set_b(const double &b) { m_b = b; }
    inline void set_c(const double &c) { m_c = c; }
    inline double get_a() const { return m_a; }
    inline double get_b() const { return m_b; }
    inline double get_c() const { return m_c; }

    // Méthodes
    void display() const; // Affiche les informations de la droite
    
};