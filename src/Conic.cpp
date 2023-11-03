#include <iostream>


#include "Conic.hpp"

Conic::Conic(const double a, const double b, const double c, const double d, const double e, const double f)
: m_a(a), m_b(b), m_c(c), m_d(d), m_e(e), m_f(f)
{}

Conic::Conic(const Point2P x1, const Point2P x2, const Point2P x3, const Point2P x4, const Point2P x5) 
{
    // Ajouter code de constructeur de conique à partir de 5 points -----------------------------------------------------------------------------

    /*
    alors de ce que j'ai compris deja on crée la matrice relative au systeme (page 2 énoncé) avec w=1, puis on calcule son noyeau

    Eigen::MatrixXd A(5,6);
    A.leftCols(5).setZero();    //initialise les 5 premières colonnes à zéro
    A.col(5).setOnes();         //remplit la dernière colonne de 1

    A(0,0) = pow(x1.x,2)
    A(0,1) = x1.x*x1.y
    A(0,2) = pow(x1.y,2)
    A(0,3) = x1.x
    A(0,4) = x1.y   //... faire pareil pour les 4 autres points
    
    pour calculer noyau jsp on fait comment mais ya ca dans l'énoncé :
    Eigen :: JacobiSVD < Eigen :: MatrixXd > svd (A ,
                            Eigen :: ComputeThinU | Eigen :: ComputeFullV );
    Eigen :: VectorXd x = svd . matrixV (). rightCols (1);
    
    
    
    */
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