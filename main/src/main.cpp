#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

#include "Line2D.hpp"
#include "Point2D.hpp"
#include "Conic.hpp"
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


  // création de la conique
  std::vector<geomproj::Point2D> points = randgen::pointsVectorGenerator(6); // Génération de 5 points aléatoires
  conic::Conic myConic = conic::Conic(points[0], points[1], points[2], points[3], points[4]); // Appel du constructeur de conique avec les 5 points aléatoires
  conic::Conic myConicFrom6Points = conic::Conic(points[0], points[1], points[2], points[3], points[4], points[5]); // Appel du constructeur de conique avec les 5 points aléatoires

  // génération d'un point à l'infini
  geomproj::Point2D idealPoint = randgen::idealPoint2DGenerator();
  // dessin des points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2), pt6(2), infpt(2);
  pt1 <<  points[0].get_x(),  points[0].get_y();
  pt2 <<  points[1].get_x(),  points[1].get_y();
  pt3 <<  points[2].get_x(),  points[2].get_y();
  pt4 <<  points[3].get_x(),  points[3].get_y();
  pt5 <<  points[4].get_x(),  points[4].get_y(); 
  pt6 <<  points[5].get_x(),  points[5].get_y();
  infpt << idealPoint.get_x(), idealPoint.get_y();

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, "p3", 200,0,0);
  viewer.push_point(pt4, "p4", 200,0,0);
  viewer.push_point(pt5, "p5", 200,0,0);
  viewer.push_point(pt6, "p6", 100,0,0);
  viewer.push_point(infpt, "infpt", 200,0,200);
  

  // dessin de la conique
  Eigen::VectorXd conic(6);
  conic << myConic.get_a(), myConic.get_b(), myConic.get_c(), myConic.get_d(), myConic.get_e(), myConic.get_f();
  viewer.push_conic(conic, 0,0,200);

  // dessin de la conique avec 6 points
  Eigen::VectorXd conic2(6);
  conic2 << myConicFrom6Points.get_a(), myConicFrom6Points.get_b(), myConicFrom6Points.get_c(), myConicFrom6Points.get_d(), myConicFrom6Points.get_e(), myConicFrom6Points.get_f();
  viewer.push_conic(conic2, 0,200,200);

  // Conique avec un point à l'infini
  conic::Conic myConicFromInf = conic::Conic(points[0], points[1], points[2], points[3], idealPoint); // Appel du constructeur de conique avec les 5 points aléatoires et le dernier à l'infini

  // dessin de la conique en vertavec un point à l'infini
  Eigen::VectorXd conic3(6);
  conic3 << myConicFromInf.get_a(), myConicFromInf.get_b(), myConicFromInf.get_c(), myConicFromInf.get_d(), myConicFromInf.get_e(), myConicFromInf.get_f();
  viewer.push_conic(conic3, 0,250,0);
  // draw line
  viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  // Création et dessin d'une conique à partir de 5 points aléatoires



  return 0;
}

