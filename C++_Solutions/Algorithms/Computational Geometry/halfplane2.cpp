#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x) {
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    return 1;
}

struct Point {
    double x, y;
    Point(){}
    Point(double xx, double yy) : x(xx), y(yy){}
    Point operator - (const Point &b) const {
        return Point(x-b.x, y-b.y);
    }
    double operator ^ (const Point &b) const {
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b) const {
        return x*b.x + y*b.y;
    }
};

struct Line {
    Point s, e;
    double k;
    Line(){}
    Line(Point ss, Point ee) {
        s = ss; e = ee;
        k = atan2(e.y-s.y, e.x-s.x);
    }
    Point operator &(const Line &b) const {
        Point res = s;
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return res;
    }
};

//half plane intersection
int HPIcmp(Line a, Line b) {
    if(fabs(a.k-b.k) > eps) return a.k < b.k;
    return ((a.s-b.s)^(b.e-b.s)) < 0;
}

Line Q[110];
void HPI(Line line[], int n, Point res[], int &resn) {
    int tot = n;
    sort(line, line+n, HPIcmp);
    tot = 1;
    for(int i = 1; i < n; i++)
        if(fabs(line[i].k-line[i-1].k) > eps)
        line[tot++] = line[i];
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for(int i = 2; i < tot; i++) {
        if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s)) < eps ||
           fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
            return;
        while(head < tail && (((Q[tail]&Q[tail-1])-line[i].s)^(line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (((Q[head]&Q[head+1])-line[i].s)^(line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (((Q[tail]&Q[tail-1])-Q[head].s)^(Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (((Q[head]&Q[head-1])-Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
        head++;
    if(tail <= head+1) return;
    for(int i = head; i < tail; i++)
        res[resn++] = Q[i]&Q[i+1];
    if(head < tail-1)
    res[resn++] = Q[head]&Q[tail];
}

Point p[110];
Line line[110];
double dist(Point a, Point b) {
    return sqrt((a-b)*(a-b));
}

void change(Point a, Point b, Point &c, Point &d, double p) {
    double len = dist(a,b);
    double dx = (a.y-b.y)*p/len;
    double dy = (b.x-a.x)*p/len;
    c.x = a.x + dx; c.y = a.y + dy;
    d.x = b.x + dx; d.y = b.y + dy;
}

ostream &operator << (ostream &os, const Point &p) {
    os << "(" << p.x << "," << p.y << ")";
}

Point pp[110];
int main() {
    freopen("halfplane.in", "r", stdin);
    int n;
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        double l = 0, r = 100000;
        double ans = 0;
        while(r-l >= eps)
        {
            double mid = (l+r)/2;
            for(int i = 0; i < n; i++)
            {
                Point t1, t2;
                change(p[i], p[(i+1)%n], t1, t2, mid);
                line[i] = Line(t1, t2);
                /*if (p[2].x == 5000)
                    cout << "Line: " << line[i].s << " " << line[i].e << endl;*/
            }
            //cout << endl;
            int resn;
            HPI(line, n, pp, resn);
            if(resn == 0)
                r = mid - eps;
            else
            {
                ans = mid;
                l = mid + eps;
            }
        }
        printf("%.6f\n", ans);
    }
    return 0;
}
