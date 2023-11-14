#include <iostream>
#include <vector>
#include <cassert>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

#include "Line2D.hpp"
#include "Point2D.hpp"
#include "Conic.hpp"
#include "ConicPencil.hpp"
#include "Random.hpp"

int main()
{
  // the viewer will open a file whose path is writen in hard (bad!!). 
  // So you should either launch your program from the fine directory or change the path to this file.
  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);


  // génération de points aléatoires
  std::vector<geomproj::Point2D> points = randgen::pointsVectorGenerator(11); // Génération de 11 points aléatoires


  // Initialisation des coniques 
  conic::Conic myConic, myConicFrom6Points;

  // CREATION DES CONIQUES ROUGE ET BLEUE 
  try {
  // Création de conique avec 5 points aléatoires
  myConic = conic::Conic(points[0], points[1], points[2], points[3], points[4]);

  // dessin de la conique rouge avec 5 points
  Eigen::VectorXd conic(6);
  conic << myConic.get_a(), myConic.get_b(), myConic.get_c(), myConic.get_d(), myConic.get_e(), myConic.get_f();
  viewer.push_conic(conic, 200,0,0);


  //Conique avec 6 points aléatoires
  myConicFrom6Points = conic::Conic(points[5], points[6], points[7], points[8], points[9], points[10]); // Appel du constructeur de conique avec les 6 points aléatoires
  
  // dessin de la conique bleue avec 6 points
  Eigen::VectorXd conic2(6);
  conic2 << myConicFrom6Points.get_a(), myConicFrom6Points.get_b(), myConicFrom6Points.get_c(), myConicFrom6Points.get_d(), myConicFrom6Points.get_e(), myConicFrom6Points.get_f();
  viewer.push_conic(conic2, 0,0,200);
  
  } catch (const std::exception& e) {
    std::cerr << "Exception capturée dans la création des coniques rouge et bleue: " << e.what() << std::endl;
  }

  // Initialisation du faisceau de conique
  conic::ConicPencil myConicPencil;
  
  // Création du faisceau
  try {
    myConicPencil = conic::ConicPencil(myConic, myConicFrom6Points); // Création du faisceau de coniques avec deux des coniques déjà créées.
  } catch (const std::exception& e) {
    std::cerr << "Exception capturée dans la création du faisceau de coniques : " << e.what() << std::endl;
  }
  
  // Création des coniques grises du faisceauet dessin
  try {
    std::vector<conic::Conic> myConicsFromPencil = randgen::conicsFromConicPencilGenerator(myConicPencil, 5); // 5 Coniques à partir du faisceau de coniques
    
    // dessin des coniques grises du faisceau 
    std::vector<std::string> conicsNames = {"cf1", "cf2", "cf3", "cf4", "cf5"}; // Noms des coniques du faisceau
    Eigen::VectorXd cf1(6), cf2(6), cf3(6), cf4(6), cf5(6); // Initialisation des coniques (a b c d e f)
    std::vector<Eigen::VectorXd> conicsToDraw = {cf1, cf2, cf3, cf4, cf5}; //vecteur de coniques à dessiner
    for(size_t i = 0; i<myConicsFromPencil.size(); i++) {
      conicsToDraw[i] << myConicsFromPencil[i].get_a(), myConicsFromPencil[i].get_b(), myConicsFromPencil[i].get_c(), myConicsFromPencil[i].get_d(), myConicsFromPencil[i].get_e(), myConicsFromPencil[i].get_f(); // Renseignement des valeurs de abcdef
      viewer.push_conic(conicsToDraw[i], 200,200,200);
    }

  } catch (const std::exception& e) {
    std::cerr << "Exception capturée dans la création des coniques du faisceau : " << e.what() << std::endl;
  }
  
  // dessin des points
  std::vector<std::string> pointsNames = {"p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10", "p11"}; // Noms des points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2), pt6(2), pt7(2), pt8(2), pt9(2), pt10(2), pt11(2); // Initialisation des points (x, y)
  std::vector<Eigen::VectorXd> pointsToDraw = {pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8, pt9, pt10, pt11}; //vecteur de points à dessiner
  for(size_t i = 0; i<pointsToDraw.size(); i++) {
    pointsToDraw[i] << points[i].get_x(), points[i].get_y(); // Renseignement de la valeur
    viewer.push_point(pointsToDraw[i], pointsNames[i], 200,0,0); // Dessin des points
  }

  // La génération d'une conique à partir d'un point à l'infini cause une erreur :
  // // génération d'un point à l'infini
  // geomproj::Point2D idealPoint = randgen::idealPoint2DGenerator();

  // // Conique avec un point à l'infini
  // conic::Conic myConicFrominf; // Initialisation
  // myConicFromInf = conic::Conic(points[0], points[1], points[2], points[3], idealPoint); // Appel du constructeur de conique avec les 5 points aléatoires et le dernier à l'infini

  // // dessin de la conique en verte avec un point à l'infini
  // Eigen::VectorXd conic3(6);
  // conic3 << myConicFromInf.get_a(), myConicFromInf.get_b(), myConicFromInf.get_c(), myConicFromInf.get_d(), myConicFromInf.get_e(), myConicFromInf.get_f();
  // viewer.push_conic(conic3, 0,100,0);

  // draw line
  viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  // Création et dessin d'une conique à partir de 5 points aléatoires

  return 0;
}

