/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
typedef long long LL;
using namespace std;

//returns inverse
long long extended_gcd (long long a, long long  b, long long  &x, long long  &y) { //x = ax y = by, ax + by = d;
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    y = (x1 - (a / b) * y1);
    x = y1;
    //cout << a << ' ' << b << ' ' << x << ' ' << y << ' ' << d << endl;
    return d;
}


//solves diophantine equation of Ax + By + C = 0;
void diophantine(long long a, long long b, long long c, long long &x, long long &y) {
    long long gcd = extended_gcd(a, b, x, y);
    if (c % gcd != 0) {
        x = -1, y = -1;
        return;
    }
    x = c/gcd * x;
    y = c/gcd * y;
}

int main() {

    //Rd("7.in");
    ios_base::sync_with_stdio(0);
    long long a, b, c, x, y;
    cin >> a >> b >> c;
    long long gcd = extended_gcd(a, b, x, y);
    c = -c;
    if (c % gcd) {
        cout << -1 << endl;
        return 0;
    }
    cout << c/gcd * x << ' ' << c/gcd * y << endl;
    //diophantine(a, b, c, x, y);
    //cout << x << y << endl;
    return 0;
}


