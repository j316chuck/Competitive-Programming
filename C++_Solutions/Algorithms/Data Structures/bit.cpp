/*
PROG: Binary Indexed Tree
USR: j316chuck
NOTES: Contains GCDSum Formula
EXTRA: Helped catch bug in sieve formula
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

////O(n log n) can be up to 10 million
const int maxn = 1e6 + 5;
bool prime[maxn];
int phi[maxn];
vector<int> primes;
void Sieve() {
    for (int i = 0; i < maxn; i++) prime[i] = true, phi[i] = i;
    prime[0] = false; prime[1] = false;
    for (int i = 2; i < maxn; i++) {
        if (prime[i]) {
            phi[i] = i - 1;
            for (int k = i + i; k < maxn; k += i) {
                phi[k] /= i;
                phi[k] *= i - 1;
                prime[k] = false;
            }
            primes.push_back(i);
        }
    }
}


//formula: sum of all gcd of n from 1 - n is
//summation of d * phi(n/d) for all d that divides n
//this is because gcd(a, n) = d if and only if gcd(1, n/a) = 1 = phi(n/a)
//complexity O(n * (1 + 1/2 + 1/3 + .. 1/n)) = O(n log n)
int gcdsum[maxn];
void GCDSum() {
    for (int gcd = 1; gcd < maxn; gcd++) {
        for (int n = gcd; n < maxn; n += gcd) {
            gcdsum[n] += gcd * phi[n/gcd];
            gcdsum[n] %= MOD;
        }
    }
}


//bit tree
//maxn is always 1 + n or more
//log n query and update time
int bit[maxn];
void Update(int x, int val) {
    for (; x < maxn; x += x & -x) {
        bit[x] += val + MOD;
        bit[x] %= MOD;
    }
}

int Query(int x) {
    int total = 0;
    for (; x > 0; x -= x & -x){
        total += bit[x];
        total %= MOD;
    }
    return total;
}

int QueryRange(int r, int l) {
    return (Query(r) - Query(l - 1) + MOD) % MOD;
}

int main() {
    //freopen("bit.in", "r", stdin);
    Sieve();
    GCDSum();
    int n;
    scanf("%d", &n);
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        Update(i, gcdsum[a[i]]);
    }

    int q, l, r; char c;
    scanf("%d ", &q);
    for (int i = 0; i < q; i++) {
        scanf("%c %d %d ", &c, &l, &r); //white space ignored with space in scanf
        if (c == 'C') {
            printf("%d\n", QueryRange(r, l));
        } else {
            Update(l, -gcdsum[a[l]]);
            a[l] = r;
            Update(l, gcdsum[a[l]]);
        }
    }

}
