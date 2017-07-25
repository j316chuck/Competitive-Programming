#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define TMAX 540000		// Segtree can't have more than TMAX elements
using namespace std;

struct vert {
	int x, bot, top, g;	// x, y of bottom and top, grass amount
};

ifstream fin("lazy_cow.in");
ofstream fout("lazy.out");
int n, k;

int depth, firstB, numL;	// Root depth is zero
int total[TMAX], alone[TMAX];	// max grass in interval and lazy helper
int startY[TMAX], endY[TMAX];	// the start, end of ith segment


bool vComp(vert a, vert b);
void inc(int ind, int amt, int a, int b);
void fix(int ind);

int main() {
	vector<vert> verts;			// All our vertical segments
	vector<int> ys;				// Stores y to construct segtree with
	fin >> n >> k;
	for (int i = 0; i < n; i++) {
		int gi, xi, yi;
		vert vL, vR;			// The left and right vert segments from this square
		fin >> gi >> xi >> yi;
		int lxi = xi - k,		lyi = yi;		    // The left point of square
		int rxi = xi + k,		ryi = yi;		    // The right point of square
		int llxi_r = 2 * (lxi-lyi) - 1,	llyi_r = 2 * (lxi+lyi) - 1; // Lower left after 45 degree spin
		int urxi_r = 2 * (rxi-ryi) + 1,	uryi_r = 2 * (rxi+ryi) + 1; // Upper right after spin
		vL.g = gi;			vR.g = -gi;		    // Add grass on left, remove on right
		vL.x = llxi_r;			vR.x = urxi_r;
		vL.bot = llyi_r;		vR.bot = llyi_r;
		vL.top = uryi_r;		vR.top = uryi_r;
		verts.push_back(vL);		verts.push_back(vR);
		ys.push_back(llyi_r);		ys.push_back(uryi_r);
	}

	sort(verts.begin(), verts.end(), vComp);
	sort(ys.begin(), ys.end());
	ys.resize(unique(ys.begin(), ys.end()) - ys.begin());	// Remove duplicates and resize
    /*for (int i = 0; i < ys.size(); i++) {
        cout << verts[i].x << ' ';
    } cout << endl;*/
	memset(alone, 0, TMAX * sizeof(int));			// Prepare segtree
	memset(total, 0, TMAX * sizeof(int));
	memset(startY, 0, TMAX * sizeof(int));
	memset(endY, 0, TMAX * sizeof(int));
	numL = ys.size() - 1;					// Number of leaves
	for (depth = 0; (1 << depth) < numL; depth++) ;
	firstB = (1 << depth) - 1;
	//cout << firstB << endl;			// Index of first leaf
	for (int i = 0; i < numL; i++) {			// Get start,end for leaves
		startY[firstB + i] = ys[i];
		endY[firstB + i] = ys[i + 1];
	}
	for (int i = firstB - 1; i >= 0; i--) {			// Get start,end for rest of tree
		startY[i] = min(startY[1 + (i << 1)], startY[2 + (i << 1)]);
		endY[i] = max(endY[1 + (i << 1)], endY[2 + (i << 1)]);
	}
    /*for (int i = 0; i < n; i++) {
        cout << startY[i] << ' ' <<  endY[i] << endl;
    }*/
	int ans = 0;
	for (int i = 0; i < verts.size(); i++) {
		inc(0, verts[i].g, verts[i].bot, verts[i].top);
		ans = max(ans, total[0]);

		//cout << verts[i].g << endl;
	}
	//cout << ans << endl;
	fout << ans << "\n";
	return 0;
}

bool vComp(vert a, vert b) {				// Sort vertical segs so left is first
	return (a.x < b.x);
}

void inc(int ind, int amt, int a, int b) {
	if (startY[ind] >= b || endY[ind] <= a) return;	// a to b is out of range
	if (startY[ind] >= a && endY[ind] <= b) {	// a to b surrounds this seg
		alone[ind] += amt;
		total[ind] += amt;
		fix(ind);				// Make sure parents still have correct data
		return;
	}
	inc(1 + (ind << 1), amt, a, b);			// a to b partially in seg
	inc(2 + (ind << 1), amt, a, b);			// go to children
}

void fix(int ind) {					// index that was disrupted
	for (int i = (ind - 1) >> 1; i >= 0; i = (i - 1) >> 1)
		total[i] = alone[i] + max(total[1 + (i << 1)], total[2 + (i << 1)]);
}
