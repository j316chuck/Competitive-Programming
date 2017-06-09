#include <iostream>
#include <cstdio>
#include <math.h>
#define EPS 0.0000000001

typedef struct s_point {
    double x, y;
} Point;
typedef struct s_line {    // line: a*x + b*y + c = 0
    double a, b, c;
} Line;

bool equal(const int p1, const int p2) {
    return abs(p1 - p2) < EPS;
}

Line bisector(Point p1, Point p2) {
     Line line;
     if (equal(p1.x, p2.x)) {
        line.a = 0.0, line.b = 1.0, line.c = - (p1.y  + p2.y) / 2.0;
     } else if (equal(p1.y, p2.y)) {
        line.a = 1.0, line.b = 0.0, line.c = - (p1.x + p2.x) / 2.0;
     } else {
        double k = - (p2.x - p1.x) / (p2.y - p1.y);
        double cx = (p1.x + p2.x) / 2.0;
        double cy = (p1.y + p2.y) / 2.0;
        double b = cy - k * cx;
        line.a = k, line.b = -1, line.c = b;
     }
     return line;
}

int main() {
    Line line;

}
