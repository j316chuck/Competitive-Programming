#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <iomanip>

#include <utility>
#include <complex>
#include <vector>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <deque>

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define x1 ___x1
#define y1 ___y1
#define x first
#define ft first
#define y second
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

const int N = 1000 * 1000 + 13;
int n, m;
pt a[N];
vector<int> q[N];

inline bool read ()
{
	if (scanf ("%d%d", &n, &m) != 2)
		return false;

	forn (i, n)
	{
		int l, r;
		assert(scanf ("%d%d", &l, &r) == 2);

		a[i] = mp(l, r);
	}

	forn (i, m)
	{
		int cnt;
		assert(scanf("%d", &cnt) == 1);

		q[i].pb(0);

		forn (j, cnt)
		{
			int p;
			assert(scanf ("%d", &p) == 1);

			q[i].pb(p);
		}

		q[i].pb(1000 * 1000 + 3);

		//sort(all(q[i]));
	}

    return true;
}

int ans[N];

vector<int> xs[N];
vector<pt> qq[N];
int t[N];

inline int sum (int r)
{
	int ans = 0;

	for (; r >= 0; r = (r & (r + 1)) - 1)
		ans += t[r];

	return ans;
}

inline int sum (int l, int r)
{
 	return sum(r) - sum(l - 1);
}

inline void inc (int i, int add)
{
	for (; i < N; i = (i | (i + 1)))
		t[i] += add;
}

inline void solve ()
{
	forn (i, n)
		xs[ a[i].y ].pb(a[i].x);

	forn (i, m)
		forn (j, sz(q[i]) - 1)
		{
		 	int l = q[i][j] + 1, r = q[i][j + 1] - 1;

		 	qq[r].pb(mp(l, i));
		}

	forn (i, N)
	{
		forn (j, sz(xs[i]))
		{
			int y = xs[i][j];
			inc(y, 1);
		}
		if (i < 10) {
        for (int j = 0; j < 10; j++) {
            cout << t[j] <<  ' ';
        }cout << endl;
		}
		forn (j, sz(qq[i]))
		{
			int id = qq[i][j].sc;
           // cout << id << ' ' << qq[i][j].ft << ' ' << i << endl;
			ans[id] += sum(qq[i][j].ft, i);
		}
	}

	forn (i, m)
	{
		printf ("%d\n", n - ans[i]);
	}
}

int main ()
{
    freopen("test.in", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    srand(time(NULL));

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    assert(read());
    solve();

    return 0;
}
