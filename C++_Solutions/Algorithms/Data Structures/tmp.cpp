#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAX  = 5e5 + 5;
const int MAX2 = 1e6 + 6;
const int MOD  = 1e9 + 7;

int phi[MAX];
int g_sum[MAX];
bitset<MAX> num;
vector<int> primes;

//Complexity : O(n)
void generate_etf() {
    phi[1] = 1;
    for (int i=2; i<MAX; ++i) {
        if (!num[i]) {
            phi[i] = i-1;
            primes.push_back (i);
        }
        for (int j=0; j<primes.size(); ++j) {
            int x = i * primes[j];
            if (x >= MAX) break;
            num.set(x);
            if (i%primes[j] == 0) {
                phi[x] = phi[i] * primes[j];
                break;
            }
            else {
                phi[x] = phi[i] * (primes[j]-1);
            }
        }
    }
}

//Complexity : O(n logn)
void pre_calculate() {
	for(int i=1; i<MAX; ++i) {
		for(int j=i, cnt=1; j<MAX; j+=i, cnt+=1) {
			g_sum[j] += i * phi[cnt];
		}
	}
}

int bit[MAX2];

//Complexity : O(logn)
void update(int x, int n, int val) {
	while (x <= n) {
		bit[x] += val;
		if(bit[x] >= MOD) {
			bit[x] -= MOD;
		}
		x += (x & (-x));
	}
}

//Complexity : O(logn)
int query(int x) {
	LL res = 0;
	while(x) {
		res += bit[x];
		x -= (x & (-x));
	}
	if (res >= MOD) {
		res %= MOD;
	}
	return (int)res;
}

int a[MAX2];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("bit.in", "r", stdin);
	#endif
	generate_etf();
	pre_calculate();
	int n, q, l, r, ans;
	char type[5];
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		update(i, n, g_sum[a[i]]);
	}
	for (int i = 1; i <= n; i++) {
        cout << g_sum[a[i]] <<' ';
	} cout << endl;
	scanf("%d", &q);
	while(q--) {
		scanf("%s %d %d", type, &l, &r);
		if (type[0] == 'C') {
			ans = query(r) - query(l - 1);
			if (ans < 0) {
				ans += MOD;
			}
			printf("%d\n", ans);
		}
		else {
			update(l, n, MOD - g_sum[a[l]]);
			a[l] = r;
			update(l, n, g_sum[a[l]]);
		}
	}
	return 0;
}
