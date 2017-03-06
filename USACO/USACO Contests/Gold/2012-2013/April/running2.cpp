#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define nmax 100005

int bit[nmax];
int bitlen;

inline void bit_init(int n) {
	for(int i = 1; i <= n; i++) {
		bit[i] = 0;
	}
	bitlen = n;
}

inline int bit_prefix_sum(int i) {
	int sum = 0;
	for(int j = i; j > 0; j -= (j & (-j))) {
		sum += bit[j];
	}
	return sum;
}

inline void bit_inc(int i) {
	for(int j = i; j <= bitlen; j += (j & (-j))) {
		bit[j]++;
	}
}

struct cow {
	long long speed;
	long long modulus;
	int rank;
};
cow cows[nmax];
long long max_speed = 0;
long long n, l, c;

inline bool sort_cow_by_modulus(cow const& a, cow const& b) {
	return a.modulus < b.modulus;
}

inline bool sort_cow_by_speed(cow const& a, cow const& b) {
	return a.speed < b.speed;
}

int main() {

	freopen("running.in","r",stdin);
	//freopen("running.out","w",stdout);
	scanf("%lld", &n);
	scanf("%lld", &l);
	scanf("%lld", &c);

	for(int i = 0; i < n; i++) {
		scanf("%lld", &cows[i].speed);
		if(cows[i].speed > max_speed) {
			max_speed = cows[i].speed;
		}
	}

	for(int i = 0; i < n; i++) {
		cows[i].modulus = (l*c*cows[i].speed) % (c * max_speed);
	}
	sort(cows, cows + n, sort_cow_by_modulus);
	int a = 0;
	int rank = 1;
	while(a < n) {
		int b = a+1;
		while(b < n && cows[a].modulus == cows[b].modulus) {
			b++;
		}
		for(int i = a; i < b; i++) {
			cows[i].rank = rank;
		}
		a = b;
		rank++;
	}

	sort(cows, cows + n, sort_cow_by_speed);
	bit_init(n);
    //for(int i = 0; i < n; i++) cout<<cows[i].modulus<<' '<<cows[i].rank<<endl;
	long long total = 0;
	long long sum_of_floors = 0;
	for(int i = 0; i < n; i++) {
		long long floor = (l*cows[i].speed) / (max_speed);
		long long addition = (floor-1)*i - sum_of_floors + (long long)bit_prefix_sum(cows[i].rank);
        //cout<<addition<<' '<<(floor-1)*i<<' '<<i<<' '<<sum_of_floors<<' '<<bit_prefix_sum(cows[i].rank)<<endl;
		total += addition;
        //cout<<total<<endl;
		sum_of_floors += floor;
		bit_inc(cows[i].rank);
		for(int i = 1; i <= n; i++) cout<<bit[i]<<' ';
        cout<<endl;
	}

	printf("%lld\n", total);
}
