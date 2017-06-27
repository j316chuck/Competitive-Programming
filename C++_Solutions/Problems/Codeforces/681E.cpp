#include <bits/stdc++.h>
#define PI acos(-1.0)
#define EPS 1e-9
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    freopen("681E.in", "r", stdin);
    double x0, y0, t, v, r0, x, y, r;
    scanf("%lf %lf %lf %lf", &x0, &y0, &t, &v);
    r0 = v * t;
    int n;
    scanf("%d", &n);
    vector< pair<double, int> > segs;
    double ang, angl, angr, angm;

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &x, &y, &r);
        double d = dist(x, y, x0, y0);
        if (d < r + EPS) {
            printf("1.0000\n");
            return 0;
        }

        if (r + r0 < d - EPS) {
            continue;
        }

        ang = atan2((y - y0), (x - x0));
        //keeps angle positive
        if (ang < 0) ang += 2 * PI;

        double tlen = sqrt(d * d - r * r);
        if (tlen < r0 + EPS) {
            angm = asin(r/d);
        } else {
            angm = acos((r0 * r0 + d * d - r * r) / (2 * r0 * d));
        }
        angl = ang - angm;
        angr = ang + angm;

        if (angl < 0) {
            segs.push_back({angl + 2 * PI, 1});
            segs.push_back({2 * PI, -1});
            segs.push_back({0, 1});
            segs.push_back({angr, -1});
        } else if (angr > (2 * PI)) {
            segs.push_back({angr - 2 * PI, -1});
            segs.push_back({0, 1});
            segs.push_back({angl, 1});
            segs.push_back({2 * PI, -1});
        } else {
            segs.push_back({angl, 1});
            segs.push_back({angr, -1});
        }

        /*for (auto it = segs.begin(); it != segs.end(); it++) {
            cout << it -> first << ' ' << it -> second << endl;
        }
        cout << endl;
        cout << endl;*/
    }

    sort(segs.begin(), segs.end());
    int c = 0;
    double total = 0, last;
    for (int i = 0; i < segs.size(); i++) {
        if (c > 0) {
            total += segs[i].first - last;
        }
        last = segs[i].first;
        c += segs[i].second;
    }

    printf("%.9f", total / (2 * PI));

    return 0;
}

