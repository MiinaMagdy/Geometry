#include <iostream>
#include <complex>

using namespace std;

#define PI acos(-1.0)
#define EPS 1e-9
#define vec(a, b)  ((b) - (a))
#define dot_prod(a, b)  real(conj(a) * (b)) 
#define cross_prod(a, b)  imag(conj(a) * (b))
#define rotateO(p, theta)  (p) * polar(1.0, theta)
#define rotateA(p, a, theta)  rotateO((p) - (a), theta) + (a)
#define reflectO(p, m)  conj((p) / (m)) * (m)
#define reflectA(p, a, m)  reflectO((p) - (a), m) + (a)

typedef complex<double> point;

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 0 if a == b | -1 if a < b | 1 if a > b 
 */
int dcmp(double a, double b) {
    return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

int isCollinear(point a, point b, point c) {
    return fabs(cross_prod(vec(a, b), vec(a, c))) <= EPS;
}

/**
 * @brief Check if point c is on the Ray ab
 * 
 * @param ab Ray
 * @param c 
 * @return true  if c is on the Ray ab
 * @return false  if c is not on the Ray ab
 */
bool isPointOnRay(point a, point b, point c) {
    if (!isCollinear(a, b, c)) return false;
    return dcmp(dot_prod(vec(a, b), vec(a, c)), 0) == 1;
}

/**
 * @brief Check if point c is on the Segment ab
 * 
 * @param ab segment
 * @param c point
 * @return true 
 * @return false 
 */

bool isPointOnSegment(point a, point b, point c) {
    return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

/**
 * @brief distance from point c to the Line ab
 * 
 * @param ab line
 * @param c point
 * @return double
 */
double distToLine(point a, point b, point c) {
    return fabs(cross_prod(vec(a, b), vec(a, c))) / abs(vec(a, b));
}

double distToSegment(point a, point b, point c) {
    point v1 = vec(a, b), v2 = vec(a, c), v3 = vec(b, c);
    if (dot_prod(v1, v2) <= 0) return abs(v2);
    if (dot_prod(v1, v3) >= 0) return abs(v3);
    return distToLine(a, b, c);
}

bool intersectSegments(point a, point b, point c, point d, point& intersect) {
    double d1 = cross_prod(vec(b, a), vec(c, d));
    if (dcmp(d1, 0) == 0) return false;
    double d2 = cross_prod(vec(c, a), vec(c, d));
    double d3 = cross_prod(vec(b, a), vec(c, a));

    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + t1 * vec(a, b);

    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS) return false;
    return true;
}

int ccw(point p0, point p1, point p2) {
    point v1(vec(p0, p1)), v2(vec(p0, p2));
    double t = cross_prod(v1, v2);
    if (dcmp(t, 0) > +EPS) return 1; // counter clockwise
    if (dcmp(t, 0) < -EPS) return -1; // clockwise
    if (v1.real() * v2.real() < -EPS || v1.imag() * v2.imag() < -EPS) return -1; // clockwise
    if (norm(v1) < norm(v2) - EPS) return +1; // counter clockwise
    return 0; // on segment
}

bool intersect(point p1, point p2, point p3, point p4) {
    bool x = (p1 == p2), y = (p3 == p4);
    if (x && y) return p1 == p3;
    if (x) return ccw(p3, p4, p1) == 0;
    if (y) return ccw(p1, p2, p3) == 0;

    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
           ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

int main() {
    // Example in Complex STL 

    complex<double> a(1, 2);
    complex<double> b(3, 4);
    complex<double> c = a + b; // 4 + 6i
    cout << c << endl; // (4, 6)
    cout << real(c) << endl; // 4
    cout << imag(c) << endl; // 6
    cout << arg(c) << endl; // 0.876058 = atan2(6/4) | arg(a) = atan2(a.imag() / a.real())
    cout << conj(c) << endl; // 4 - 6i | conj(a) = a.real() - a.imag() * i
    cout << norm(c) << endl; // 52 = 4^2 + 6^2 = abs(c)^2 | norm(a) = a * conj(a) = a.real() * a.real() + a.imag() * a.imag()
    cout << abs(c) << endl; // 7.2111 = sqrt(4^2 + 6^2) | abs(a) = sqrt(norm(a))
    cout << polar(1.0, 1.0) << endl; // 0.540302 + 0.841471i | polar(r, theta) = r * exp(i * theta)
    cout << exp(c) << endl; // -4.82981 - 15.1367i | exp(a) = e^a.real() * exp(i * a.imag())

    return 0;
}
