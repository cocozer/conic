#include <iostream>
#include <vector>

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
  // génération d'un point à l'infini
  geomproj::Point2D idealPoint = randgen::idealPoint2DGenerator();

  // création des coniques

  // Conique avec 5 points aléatoires
  conic::Conic myConic = conic::Conic(points[0], points[1], points[2], points[3], points[4]);

  //Conique avec 6 points aléatoires
  conic::Conic myConicFrom6Points = conic::Conic(points[5], points[6], points[7], points[8], points[9], points[10]); // Appel du constructeur de conique avec les 6 points aléatoires

  // Conique avec un point à l'infini aléatoire
  conic::Conic myConicFromInf = conic::Conic(points[0], points[1], points[2], points[3], idealPoint); // Appel du constructeur de conique avec les 5 points aléatoires et le dernier à l'infini
  
  // Faisceau de conique
  conic::ConicPencil myConicPencil = conic::ConicPencil(myConic, myConicFrom6Points);

  // 5 Coniques à partir du faisceau de coniques
  conic::Conic myConicFromPencil1 = myConicPencil.get_conic(randgen::floatGenerator(0, M_PI));
  conic::Conic myConicFromPencil2 = myConicPencil.get_conic(randgen::floatGenerator(0, M_PI));
  conic::Conic myConicFromPencil3 = myConicPencil.get_conic(randgen::floatGenerator(0, M_PI));
  conic::Conic myConicFromPencil4 = myConicPencil.get_conic(randgen::floatGenerator(0, M_PI));
  conic::Conic myConicFromPencil5 = myConicPencil.get_conic(randgen::floatGenerator(0, M_PI));

  // dessin des points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2), pt6(2), pt7(2), pt8(2), pt9(2), pt10(2), pt11(2), infpt(2);
  pt1 <<  points[0].get_x(),  points[0].get_y();
  pt2 <<  points[1].get_x(),  points[1].get_y();
  pt3 <<  points[2].get_x(),  points[2].get_y();
  pt4 <<  points[3].get_x(),  points[3].get_y();
  pt5 <<  points[4].get_x(),  points[4].get_y(); 
  pt6 <<  points[5].get_x(),  points[5].get_y();
  pt7 <<  points[6].get_x(),  points[6].get_y();
  pt8 <<  points[7].get_x(),  points[7].get_y();
  pt9 <<  points[8].get_x(),  points[8].get_y();
  pt10 <<  points[9].get_x(),  points[9].get_y();
  pt11 <<  points[10].get_x(),  points[10].get_y();
  infpt << idealPoint.get_x(), idealPoint.get_y();

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, "p3", 200,0,0);
  viewer.push_point(pt4, "p4", 200,0,0);
  viewer.push_point(pt5, "p5", 200,0,0);
  viewer.push_point(pt6, "p6", 250,150,0);
  viewer.push_point(pt7, "p7", 250,150,0);
  viewer.push_point(pt8, "p8", 250,150,0);
  viewer.push_point(pt9, "p9", 250,150,0);
  viewer.push_point(pt10, "p10", 250,150,0);
  viewer.push_point(pt11, "p11", 250,150,0);
  viewer.push_point(infpt, "infpt", 200,0,200);
  

  // dessin de la conique rouge avec 5 points
  Eigen::VectorXd conic(6);
  conic << myConic.get_a(), myConic.get_b(), myConic.get_c(), myConic.get_d(), myConic.get_e(), myConic.get_f();
  viewer.push_conic(conic, 200,0,0);

  // dessin de la conique bleue avec 6 points
  Eigen::VectorXd conic2(6);
  conic2 << myConicFrom6Points.get_a(), myConicFrom6Points.get_b(), myConicFrom6Points.get_c(), myConicFrom6Points.get_d(), myConicFrom6Points.get_e(), myConicFrom6Points.get_f();
  viewer.push_conic(conic2, 0,0,200);

  // dessin de la conique en verte avec un point à l'infini
  Eigen::VectorXd conic3(6);
  conic3 << myConicFromInf.get_a(), myConicFromInf.get_b(), myConicFromInf.get_c(), myConicFromInf.get_d(), myConicFromInf.get_e(), myConicFromInf.get_f();
  viewer.push_conic(conic3, 0,100,0);

  // dessin des coniques grises du faisceau 
  Eigen::VectorXd conicx(6);
  Eigen::VectorXd conicxi(6);
  Eigen::VectorXd conicxii(6);
  Eigen::VectorXd conicxiii(6);
  Eigen::VectorXd conicxiv(6);
  conicx << myConicFromPencil1.get_a(), myConicFromPencil1.get_b(), myConicFromPencil1.get_c(), myConicFromPencil1.get_d(), myConicFromPencil1.get_e(), myConicFromPencil1.get_f();
  conicxi << myConicFromPencil2.get_a(), myConicFromPencil2.get_b(), myConicFromPencil2.get_c(), myConicFromPencil2.get_d(), myConicFromPencil2.get_e(), myConicFromPencil2.get_f();
  conicxii << myConicFromPencil3.get_a(), myConicFromPencil3.get_b(), myConicFromPencil3.get_c(), myConicFromPencil3.get_d(), myConicFromPencil3.get_e(), myConicFromPencil3.get_f();
  conicxiii << myConicFromPencil4.get_a(), myConicFromPencil4.get_b(), myConicFromPencil4.get_c(), myConicFromPencil4.get_d(), myConicFromPencil4.get_e(), myConicFromPencil4.get_f();
  conicxiv << myConicFromPencil5.get_a(), myConicFromPencil5.get_b(), myConicFromPencil5.get_c(), myConicFromPencil5.get_d(), myConicFromPencil5.get_e(), myConicFromPencil5.get_f();
  viewer.push_conic(conicx, 200,200,200);
  viewer.push_conic(conicxi, 200,200,200);
  viewer.push_conic(conicxii, 200,200,200);
  viewer.push_conic(conicxiii, 200,200,200);
  viewer.push_conic(conicxiv, 200,200,200);

  // draw line
  viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  // Création et dessin d'une conique à partir de 5 points aléatoires

  return 0;
}

