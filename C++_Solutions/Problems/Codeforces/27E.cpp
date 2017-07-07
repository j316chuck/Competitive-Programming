#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
bool prime[maxn];
int phi[maxn];
vector<int> primes;
void sieve() {
    for (int i = 0; i < maxn; i++) prime[i] = true, phi[i] = i;
    prime[0] = false; prime[1] = false;
    for (int i = 2; i <= sqrt(maxn); i++) {
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

void prime_factor(int n, vector<int> &v) { //prime factors in O(sqrt(n));
    //when n is composite
    while (n % 2 == 0) {
        n /= 2;
        v.push_back(2);
    }
    //n must be odd;
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            v.push_back(i);
        }
    }
    //when n is prime;
    if (n > 2) {
        v.push_back(n);
    }
}

long long pow(int a, int n) { //does not account for overflow
    if (n == 0) return 1LL;
    if (n == 1) return 1LL * a;
    long long t = pow(a, n / 2);
    return t * t * pow (a, n % 2);
}

int main() {
    sieve();
    int n;
    scanf("%d", &n);
    vector <int> v;
    prime_factor(n, v);
    reverse(v.begin(), v.end());
    long long prod = 1;
    int c = 0;
    for (int i = 0; i < v.size(); i++) {
        prod *= 1LL * pow(primes[c++], v[i] - 1);
    }
    printf("%I64d\n", prod);
}
