const int mod = 1e9 + 7;
inline int mult(int a, int b) { long long x = a; x *= (long long) b; if(x >= mod) x %= mod; return x; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? mod - b + a : a - b; }

//PT = pair<double, double>
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


