#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>
#include <vector>
using namespace std;
using coord = double;

const double EPS = 1e-9;

int sign(coord x) { return (x > EPS) - (x < -EPS); }

struct point {
  coord x, y;

  point() : x(0), y(0) {}
  point(coord x, coord y) : x(x), y(y) {}

  double norm() { return sqrt(norm2()); }
  coord norm2() { return (*this) * (*this); }

  point operator+(const point& rhs) const { return point(x+rhs.x, y+rhs.y); }
  point operator-(const point& rhs) const { return point(x-rhs.x, y-rhs.y); }
  point operator*(const coord t) const { return point(x*t, y*t); }
  point operator/(const coord t) const { return point(x/t, y/t); }

  // produto escalar (dot product)
  coord operator*(const point& rhs) const { return x*rhs.x + y*rhs.y; }

  // produto vetorial (cross product)
  coord operator^(const point& rhs) const { return x*rhs.y - y*rhs.x; }

  // rotaciona 90 graus em sentido horario
  point perp(){ return point(-y, x); }
  point rot(point rhs) { return point((*this)^rhs, (*this)*rhs); }
  point rot(double ang) { return rot(point(sin(ang), cos(ang))); }
};

ostream& operator<<(ostream& os, point p) {
    return os<<"("<<p.x<<","<<p.y<<")";
}

struct line {
  point v; // v = q-p
  coord c;

  line(point v, coord c) : v(v), c(c) {}
  line(coord a, coord b, coord c) : v({b,-a}), c(c) {}
  line(point p, point q) : v(q-p), c(v^p) {}

  // > 0: acima, < 0: abaixo, =0: colinear
  coord side(point p) { return (v^p)-c; }
  coord dist(point p) { return abs(side(p))/v.norm(); }
  coord dist2(point p) { return side(p)*side(p)/v.norm2(); }

  line perp(point p) { return line(p, p+v.perp()); }
  point proj(point p) { return p - v.perp()*side(p)/v.norm2(); }
};

// point.rot(ccw90) eh equivalente a rotacionar 
// o ponto 90 graus em sentido anti-horario
point ccw90(1,0);

struct circle {
  point o; coord r;
  circle() {}
  circle(point o, coord r) : o(o), r(r) {}

  // checa se as circunferencias se intersectam
  bool intersect(circle c) {
    return ((sign((o-c.o).norm() - (r+c.r)) <= 0) && 
      (sign((o-c.o).norm() - fabs(r-c.r)) >= 0)); 
  }

  bool contains(point p){ return (o-p).norm()-r*r <= 0; }

  bool in(circle c){ 
    double d = (o-c.o).norm();
    return d+r - c.r <= 0; 
  }

  // devolve os pontos de interseccao entre um circulo e uma reta
  vector<point> operator^(line l) {
    coord d = l.dist(o);
    if(sign(d-r) > 0) return {};
    point proj = l.proj(o);
    if(sign(d-r) == 0) return {proj}; 
    point aux = (l.v.perp()/l.v.norm()) * sqrt(r*r-d*d);
    return {proj+aux, proj-aux};
  }

  // devolve os pontos de interseccao entre dois circulos
  vector<point> operator^(circle c){
    coord d = (o-c.o).norm();
    if(intersect(c)) return {};
    coord x = (d*d - c.r*c.r + r*r) / (2*d), y = sqrt(r*r - x*x);
    point v = (c.o-o)/d;
    vector<point> inter;
    inter.push_back(o + v*x - v.rot(ccw90)*y);
    if(y>EPS) inter.push_back(o+v*x+v.rot(ccw90)*y);
    return inter;
  }
};

int main() {
  coord xm, ym;

  while (cin >> xm >> ym) {
    point p(xm, ym), min_point;
    vector<point> points;
    double min_distance = DBL_MAX;
    int n;

    cin >> n;

    for (int i = 0; i <= n; i++) {
      coord x, y;
      cin >> x >> y;
      points.push_back(point(x, y));
    }

    for (int i = 1; i <= n; i++) {
      point p1, p2, closest_point;
      double distance;

      p1 = points[i - 1];
      p2 = points[i];

      line l1(p1, p);
      line l2(p1, p2);

      double u = (l1.v * l2.v) / l2.v.norm2();
      if (u > 1) {
        closest_point = point(p2.x, p2.y);
        distance = sqrt(pow(p2.x - p.x, 2) + pow(p2.y - p.y, 2));
      } else if (u < 0) {
        closest_point = point(p1.x, p1.y);
        distance = sqrt(pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2));
      } else {
        closest_point = p1 + l2.v * u;
        distance = sqrt(pow(closest_point.x - p.x, 2) + pow(closest_point.y - p.y, 2));
      }

      if (distance < min_distance) {
        min_point = closest_point;
        min_distance = distance;
      }
    }

    cout << fixed << setprecision(4) << min_point.x << "\n";
    cout << fixed << setprecision(4) << min_point.y << "\n";
  }

  return 0;
}
