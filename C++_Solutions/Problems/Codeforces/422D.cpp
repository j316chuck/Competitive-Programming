#include <bits/stdc++.h>
using namespace std;

//calculate prime factor in O(log n)
//basic idea is calculate sieve and record the first prime
//then use while loop to keep on recording the least prime of n
const int maxn = 5e6 + 5;
const int mod = 1e9 + 7;
bool prime[maxn];
int divisor[maxn];
long long f[maxn];
void sieve() {
    for(int i = 2; i < maxn; i++) {
        prime[i] = true;
    }
    for(int i = 2; i < maxn; i++) {
        if(prime[i]) {
            divisor[i] = i;
            for(int j = 2; i * j < maxn; j++) {
                prime[i*j] = false;
                if (divisor[i*j] == 0) {
                    divisor[i*j] = i;
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("422D.in", "r", stdin);
    sieve();
    long long t, l, r;
    cin >> t >> l >> r;
    f[1] = 1;
    for (long long i = 2; i <= r; i++) {
        if (prime[i]) {
            f[i] = i * (i-1) / 2;
        } else {
            f[i] = (i / divisor[i]) * f[divisor[i]] + f[i / divisor[i]];
        }
        f[i] %= mod;
    }
    long long ans = 0;
    long long pow = 1;
    for (long long i = l; i <= r; i++) {
        ans += f[i] * pow;
        ans %= mod;
        pow = pow * t;
        pow %= mod;
    }
    cout << ans << endl;
}

