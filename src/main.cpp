#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

#include "Line2P.hpp"
#include "Point2P.hpp"
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
  std::vector<Point2P> points = randgen::pointsVectorGenerator(5); // Génération de 5 points aléatoires
  Conic myConic = Conic(points[0], points[1], points[2], points[3], points[4]); // Appel du constructeur de conique avec les 5 points aléatoires

  // dessin des points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2);
  pt1 <<  points[0].get_x(),  points[0].get_y();
  pt2 <<  points[1].get_x(),  points[1].get_y();
  pt3 <<  points[2].get_x(),  points[2].get_y();
  pt4 <<  points[3].get_x(),  points[3].get_y();
  pt5 <<  points[4].get_x(),  points[4].get_y();

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, "p3", 200,0,0);
  viewer.push_point(pt4, "p4", 200,0,0);
  viewer.push_point(pt5, "p5", 200,0,0);
  

  // dessin de la conique
  Eigen::VectorXd conic(6);
  conic << myConic.get_a(), myConic.get_b(), myConic.get_c(), myConic.get_d(), myConic.get_e(), myConic.get_f();
  viewer.push_conic(conic, 0,0,200);

  // draw line
  viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  Point2P myPoint = Point2P(1.0, 2.0, 1.0);
  myPoint.display();

  Line2P myLine = Line2P(6.0, 7.0, 8.0);
  myLine.display();

  // Création et dessin d'une conique à partir de 5 points aléatoires



  return 0;
}

