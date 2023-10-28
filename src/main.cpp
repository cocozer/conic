#pragma once
#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

#include "Line2P.hpp"
#include "Point2P.hpp"


//test git oui
// cc corentin je sais que tu as plagié ton court métrage sur un court métrage existant car je l'ai étudié en cours de théatre je vais faire du chantage maintenant si tu fais pas les conics tt seul je te dénonce au prof et tu aura zero/20 en théatre bisou
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

  // draw points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2);
  pt1 <<  1.5,  2.0;
  pt2 <<  3.0,  1.0;
  pt3 << -2.0, -1.0;

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, 200,0,0);

  // draw line
  viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // draw conic
  Eigen::VectorXd conic(6);
  conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;
  viewer.push_conic(conic, 0,0,200);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  Point2P myPoint = Point2P(1.0, 2.0, 1.0);
  myPoint.display();

  Line2P myLine = Line2P(6.0, 7.0, 8.0);
  myLine.display();
  return 0;
}

