const int mod = 1e9 + 7;
inline int mult(int a, int b) { long long x = a; x *= (long long) b; if(x >= mod) x %= mod; return x; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? mod - b + a : a - b; }
