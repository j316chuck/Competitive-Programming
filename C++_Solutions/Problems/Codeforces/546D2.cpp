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
const int maxn = 5e6 + 1;
bool prime[maxn];
int divisor[maxn];
void Sieve() {
    for(int i = 2; i < maxn; i++) {
        prime[i] = true;
    }
    for(int i = 2; i< maxn; i++) {
        if(prime[i]) {
            divisor[i] = i;
            for(int j = 2; i * j < maxn; j++) {
                prime[i*j] = false;
                if(divisor[i*j] == 0) {
                    divisor[i*j] = i;
                }
            }
        }
    }
}

//counts the total number of factors in i!, stored in factors[i]. complexity is in O(n)
long long factors[maxn];
void CountFactors() {
    factors[1] = 0;
    for (int i = 2; i < maxn; i++) {
        factors[i] = factors[i-1];
        for (int j = i; j > 1; j /= divisor[j]) {
            factors[i]++;
        }
    }
}

int main() {

    //Rd("546D.in");
    ios_base::sync_with_stdio(0);
    Sieve();
    CountFactors();
    int t;
    scanf("%d", &t);
    int a, b;
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", factors[a] - factors[b]);
    }
    return 0;
}
