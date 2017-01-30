/*
ID:
PROG:
LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int iN;
vector<int> vIn;
vector<int> vRes;
int iPermN=0;

void BTWork(int i)
{
	//cout <<"i=" <<i <<endl;
	if (vRes.size() == iN)
	{
		for(int k=0; k<vRes.size(); k++)
		{
			cout << vRes[k];
			if (k==vIn.size()-1)
				cout << endl;
			else
				cout << ',';
		}
		iPermN++;
		return;
	}
	//if (vIn[i] == 0)
		//return;
	//vRes.push_back(vIn[i]);
	//vIn[i] = 0;
	for(int n=0; n<vIn.size(); n++)
	{
		if(vIn[n] == 0)
			continue;
		int s=vIn[n];
		vRes.push_back(s);
		vIn[n] = 0;
		BTWork(n+1);
		vIn[n] = s;
		vRes.pop_back();
	}
}

int main(int argc, char** argv)
{
	// input N positive integer
	// output Permuation number list


	cin >> iN;
	for(int i=0; i<iN; i++)
	{
		int iD;
		cin >> iD;
		vIn.push_back(iD);
	}

	BTWork(0);
}


