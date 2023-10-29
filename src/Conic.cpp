#include <iostream>


#include "Conic.hpp"

Conic::Conic(const double a, const double b, const double c, const double d, const double e, const double f)
: m_a(a), m_b(b), m_c(c), m_d(d), m_e(e), m_f(f)
{}

Conic::Conic(const Point2P x1, const Point2P x2, const Point2P x3, const Point2P x4, const Point2P x5) 
{
    // Ajouter code de constructeur de conique à partir de 5 points -----------------------------------------------------------------------------
}

Conic::Conic(const Conic &conic) 
: m_a(conic.m_a), m_b(conic.m_b), m_c(conic.m_c), m_d(conic.m_d), m_e(conic.m_e), m_f(conic.m_f)
{}

void Conic::display() const {
	std::cout << "a = " << get_a() << std::endl;
    std::cout << "b = " << get_b() << std::endl;
    std::cout << "c = " << get_c() << std::endl;
    std::cout << "d = " << get_d() << std::endl;
    std::cout << "e = " << get_e() << std::endl;
    std::cout << "f = " << get_f() << std::endl;
}