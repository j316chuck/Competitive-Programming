#include <bits/stdc++.h>
using namespace std;

/*
0) struct pp
1) read in input
2) break into two arrays and sort both vectors with indexes. pp
3) merge the two arrays into one. 
4) if the val is > than the other return the index
*/

struct pp {
	int val, ind;
	bool operator < (const pp &a) const {
		return val < a.val;
	};
};

void solve() {
	int n; cin >> n; 
	vector<pp> even, odd, sorted;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		if (i % 2 == 0) {
			even.push_back({v, i});
		} else {
			odd.push_back({v, i});
		}
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) sorted.push_back(even[i / 2]);
		else sorted.push_back(odd[i / 2]);
	}
	for (int i = 1; i < n; i++) {
		if (sorted[i].val < sorted[i - 1].val) {
			printf("%d\n", i - 1);
			return;
		}
	}
	printf("OK\n");
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}
