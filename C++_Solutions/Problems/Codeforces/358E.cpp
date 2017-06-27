#include <bits/stdc++.h>
using namespace std;

struct PT {
    long long x, y;
};

//area of triangle a, b, c
long long area(PT a, PT b, PT c) {
    return fabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) / 2;
}

int main() {
    //freopen("33D.in", "r", stdin);
    int n; long long s;
    scanf("%d %I64d", &n, &s);

    vector<PT> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &v[i].x, &v[i].y);
    }
    //calculates maximum area of triangle within n points in O(n^2)
    bool exit;
    int a = 0, b = 1, c = 2;
    while (1) {
        exit = true;
        for (int i = 0; i < n; i++) {
            if (area(v[a], v[b], v[c]) < area(v[i], v[b], v[c])) a = i, exit = false;
            if (area(v[a], v[b], v[c]) < area(v[a], v[i], v[c])) b = i, exit = false;
            if (area(v[a], v[b], v[c]) < area(v[a], v[b], v[i])) c = i, exit = false;
        }
        if (exit) break;
    }
    //creating triangle from midpoints
    printf("%I64d %I64d\n", v[a].x  + v[b].x - v[c].x, v[a].y + v[b].y - v[c].y);
    printf("%I64d %I64d\n", v[b].x  + v[c].x - v[a].x, v[b].y + v[c].y - v[a].y);
    printf("%I64d %I64d\n", v[c].x  + v[a].x - v[b].x, v[c].y + v[a].y - v[b].y);
}
