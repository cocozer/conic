#pragma once
#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Point2P.hpp"


class Conic
{
    private :
    double m_a;
    double m_b;
    double m_c;
    double m_d;
    double m_e;
    double m_f;

    public :
    // Constructeurs et Destructeur
    Conic(const double a, const double b, const double c, const double d, const double e, const double f); // Constructeur d'une Conique

    Conic(const Point2P x1, const Point2P x2, const Point2P x3, const Point2P x4, const Point2P x5); // Constructeur d'une Conique à partir de 5 points

    Conic(const Conic &c); // Constructeur par copie

    ~Conic() = default; // Appelle les destructeurs par défaut de a, b, c, d, e et f

    //Getters et Setters en Inline pour améliorer la lisibilité du code
    inline void set_a(const double &a) { m_a = a; }
    inline void set_b(const double &b) { m_b = b; }
    inline void set_c(const double &c) { m_c = c; }
    inline void set_d(const double &d) { m_d = d; }
    inline void set_e(const double &e) { m_e = e; }
    inline void set_f(const double &f) { m_f = f; }
    inline double get_a() const { return m_a; }
    inline double get_b() const { return m_b; }
    inline double get_c() const { return m_c; }
    inline double get_d() const { return m_d; }
    inline double get_e() const { return m_e; }
    inline double get_f() const { return m_f; }

    // Méthodes
    void display() const; // Affiche les informations de la conique
    Eigen::MatrixXd matrix() const; // Renvoi une matrice de la conique
    
};