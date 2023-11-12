#pragma once
#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Conic.hpp"

namespace conic {
class ConicPencil
{
    private :
    Conic m_conic1;
    Conic m_conic2;

    public:
    // Constructeurs et Destructeurs
    ConicPencil(); // Constructeur par défaut
    ConicPencil(const Conic &c1, const Conic &c2); // Constructeur classique avec 2 coniques

    ConicPencil(const ConicPencil &cp); // Constructeur par copie

    ~ConicPencil() = default; // Appelle les destructeurs par défaut des deux coniques

    //Getters et Setters en Inline pour améliorer la lisibilité du code
    inline void set_c1(const Conic &c1) {  m_conic1 = c1; }
    inline void set_c2(const Conic &c2) {  m_conic1 = c2; }
    inline Conic get_c1() const { return m_conic1; }
    inline Conic get_c2() const { return  m_conic2; }

    Conic get_conic(const float &var); // renvoie une conique C(var) de paramètre var
};
}