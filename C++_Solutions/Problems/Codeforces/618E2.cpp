#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

double sqrDist(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sqrDist(x1, y1, x2, y2));
}

const double PI = acos(-1.0);

int main() {
    freopen("681E.in", "r", stdin);
    int x0, y0, v, t;

    scanf("%d%d%d%d", &x0, &y0, &v, &t);

    double r0 = 1.0 * v * t;

    int n;
    scanf("%d", &n);

    vector<pair<double, int> > a;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        double d = sqrDist(x, y, x0, y0);
        if (d < 1.0 * r * r + eps) {
            printf("%.11f", 1.0);
            return 0;
        }
        d = sqrt(d);
        if (r + r0 < d - eps) {
            continue;
        }

        double angL, angR, ang;
        double angM = atan2(y - y0, x - x0);
        if (angM < 0) {
            angM += 2 * PI;
        }

        double tLen = sqrt(d * d - 1.0 * r * r);
        if (tLen < r0 + eps) {
            ang = asin(r / d);
        } else {
            ang = acos((d * d + r0 * r0 - 1.0 * r * r) / (2 * d * r0));
        }

        angL = angM - ang;
        angR = angM + ang;
        cout << angL << ' ' << angR << endl;
        if (angL < 0) {
            a.push_back(make_pair(angL + 2 * PI, 1));
            a.push_back(make_pair(2 * PI, -1));
            a.push_back(make_pair(0.0, 1));
            a.push_back(make_pair(angR, -1));
        } else if (angR > 2 * PI) {
            a.push_back(make_pair(angL, 1));
            a.push_back(make_pair(2 * PI, -1));
            a.push_back(make_pair(0.0, 1));
            a.push_back(make_pair(angR - 2 * PI, -1));
        } else {
            a.push_back(make_pair(angL, 1));
            a.push_back(make_pair(angR, -1));
        }
        /*for (auto it = a.begin(); it != a.end(); it++) {
            cout << it -> first << ' ' << it -> second << endl;
        }
        cout << endl;
        cout << endl;*/
    }

    sort(a.begin(), a.end());

    double last = 0;
    int c = 0;
    double ans = 0;

    for (auto& p : a) {
        if (c > 0) {
            ans += p.first - last;
        }
        c += p.second;
        last = p.first;
    }

    ans /= 2 * PI;
    printf("%.11f", ans);

    return 0;
}
