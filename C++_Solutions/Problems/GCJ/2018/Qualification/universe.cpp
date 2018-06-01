#include <bits/stdc++.h>
using namespace std;

/*
1) starter code for C++ GCJ 
2) read in the string and then evaluate the current sum and array sum
3) then from the back use a while loop to continue popping the array. 
*/

int solve() {
	string p;
	int d = 0, c = 0, s = 0, mx = 0, sum = 0, power = 0, result = 0;
	cin >> d >> p;
	int bits[32] = {0};
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'C') { 
			power++;
			c++;
		} else {
			sum += pow(2, power);
			s++;
			bits[power]++;
			mx = max(mx, power);
		}
	} 
	if (s > d) {
		return -1;
	}
	
	power = mx;
	while (sum > d) {
		if (bits[power] == 0) {
			power--;
		}
		bits[power]--;
		bits[power - 1]++;
		sum -= (int) pow(2, power - 1);
		result++;
	}
	return result;
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int res = solve();
		printf("Case #%d: ", i);
		if (res == -1) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", res);
		}
	}
}


