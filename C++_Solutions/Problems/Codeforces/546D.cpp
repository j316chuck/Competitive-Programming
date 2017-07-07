/*
ID: j316chuck
PROG: 546D
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

//calculate prime factor in O(log n)
//basic idea is calculate sieve and record the first prime
//then use while loop to keep on recording the least prime of n
//based on idea of sieve
//counts the total number of factors in i!, stored in factors[i]. complexity is in O(n)
const int maxn = 5e6 + 1;
int divisor[maxn];
void CountFactorialDivisors() {
    for(int i = 2; i < maxn; i++) {
        if (!divisor[i]) {
            for (int j = i; j < maxn; j += i) {
                divisor[j] = divisor[j/i] + 1;
            }
        }
    }
    for (int i = 1; i < maxn; i++) {
        divisor[i] += divisor[i-1];
    }
}

int main() {

    //Rd("546D.in");
    ios_base::sync_with_stdio(0);
    CountFactorialDivisors();
    int t;
    scanf("%d", &t);
    int a, b;
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", divisor[a] - divisor[b]);
    }
    return 0;
}



