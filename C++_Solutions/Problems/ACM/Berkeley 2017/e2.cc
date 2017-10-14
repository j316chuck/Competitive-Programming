#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stdarg.h>
#include <cstring>
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;


double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve(vector< pair<double, double> > &v, int num) {
    double maxDistance = 0.0;
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = i + 1; j < (int) v.size(); j++) {
            maxDistance = max(maxDistance, dist(v[i].first, v[i].second, v[j].first, v[j].second));
        }
    }
    printf("Set #%d: Diameter is %.2f\n", num, maxDistance);
}

int main() {
    //freopen("input.in", "r", stdin);
    double x, y;
    char c1, c2;
    int testcase = 1;
    vector< pair<double, double> > v;
    while (scanf("%lf%c%lf%c", &x, &c1, &y, &c2) != EOF) {
        if (c2 == '\n') {
            v.push_back({x, y});
            solve(v, testcase++);
            v.clear();
        } else {
            v.push_back({x, y});
        }
    }
    return 0;
}



