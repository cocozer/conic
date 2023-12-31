#pragma once
#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Point2D.hpp"
#include "Constants.hpp"


namespace conic {
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
    Conic(); // Constructeur par défaut

    Conic(const double &a, const double &b, const double &c, const double &d, const double &e, const double &f); // Constructeur d'une Conique

    // Constructeur d'une Conique à partir de 5 points ou +
    template <typename... Points>
    Conic(Points... points) {
        if (sizeof...(points) < 5) {
            throw std::invalid_argument("Au moins 5 points doivent être fournis pour construire une conique.");
        }

        std::vector<geomproj::Point2D> pointVector = {points...}; // Crée un vecteur à partir des points fournis

        
        Eigen::MatrixXd A(sizeof...(points), 6); // Initialisation de la matrice du système
        A.col(5).setOnes(); // Remplit la dernière colonne de 1

        size_t i = 0;
        for (const auto& point : pointVector) {
            A(i, 0) = point.get_x() * point.get_x();
            A(i, 1) = point.get_x() * point.get_y();
            A(i, 2) = point.get_y() * point.get_y();
            A(i, 3) = point.get_x();
            A(i, 4) = point.get_y();
            i++;
        }

        try {
            Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
            Eigen::VectorXd x = svd.matrixV().rightCols(1);

            set_a(x(0));
            set_b(x(1));
            set_c(x(2));
            set_d(x(3));
            set_e(x(4));
            set_f(x(5));
        } catch (const std::exception& e) {
            throw std::runtime_error("Erreur lors de la construction de la conique : " + std::string(e.what()));
        }

        if (pointVector.size() == 5) {
            for (const auto& point : pointVector) {
                assert(has(point) && "La conique ne passe pas par un des points fournis.");
            }
        }
        
    }

    Conic(const Eigen::MatrixXd &A); // Constructeur par matrice

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
    Eigen::MatrixXd get_matrix() const; // Renvoie une matrice de la conique
    bool has(const geomproj::Point2D &point) const; // Renvoie vrai si le point appartient à la conique
    bool has(const geomproj::Line2D &line) const; // Renvoie vrai si la doite est une tangente à la conique
    
    // Surcharge des opérateurs
    Conic& operator=(const Conic &conic);
};
}