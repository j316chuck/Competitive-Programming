#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
bool prime[maxn];
int divisor[maxn];
vector<int> primes;

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i < maxn; i++) {
        if(prime[i]) {
            primes.push_back(i);
            divisor[i] = i;
            for(int j = 2; i * j < maxn; j++) {
                prime[i * j] = false;
                if(divisor[i * j] == 0) {
                    divisor[i * j] = i;
                }
            }
        }
    }
}

//calculates prime factors in O(n ^ 1/2);
void prime_factor(int n, vector<int> &v) {
    int sqt = sqrt(n);
    for (int i = 0; i < primes.size() && primes[i] <= sqt; i++) {
        if (n % primes[i] == 0) {
            v.push_back(primes[i]);
            while (n % primes[i] == 0) {
                n /= primes[i];
            }
        }
    }
    if (n >= 2) {
        v.push_back(n);
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

set< pair<int, int> > s;
void bfs() {
    priority_queue< pair<int, int> > pq;
    pq.push({0, 0});
    pair<int, int> top;
    while (!pq.empty()) {
        top = pq.top();
        pq.pop();
        if (s.find(top) != s.end()) {
            continue;
        }
        s.insert(top);
        if (top.first + 2 <= 30 && top.second + 1 <= 30) {
            pq.push({top.first + 2, top.second + 1});
        }
        if (top.first + 1 <= 30 && top.second + 2 <= 30) {
            pq.push({top.first + 1, top.second + 2});
        }
    }
}

vector<int> divisors;
void calc() {
    int a, b;
    scanf("%d %d", &a, &b);
    int d = gcd(a, b);
    divisors.clear();
    prime_factor(d, divisors);
    sort(divisors.begin(), divisors.end());
    reverse(divisors.begin(), divisors.end());
    for (int i = 0; i < divisors.size(); i++) {
        int count_a = 0, count_b = 0;
        while (a % divisors[i] == 0) {
            count_a++;
            a = a / divisors[i];
        }
        while (b % divisors[i] == 0) {
            count_b++;
            b = b / divisors[i];
        }
        if (s.find({count_a, count_b}) == s.end()) {
            printf("No\n");
            return;
        }
    }
    if (a != 1 || b != 1) {
        printf("No\n");
        return;
    }
    printf("Yes\n");
}

int main() {
    //freopen("426C.in", "r", stdin);
    int n;
    scanf("%d ", &n);
    bfs();
    sieve();
    for (int i = 0; i < n; i++) {
        calc();
    }
}

