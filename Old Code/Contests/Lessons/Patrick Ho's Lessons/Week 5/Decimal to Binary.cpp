/*
ID:j316chuck
PROG:gift1
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


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int main()
{
   int N;
	cin>>N;
	for(int i = 0; i< N; i++)
	{
	int X;
	cin>>X;

	vector<int> result;

	while(X!=0)
	{
		int a = X%2;
		result.push_back(a);

		X= X>>1;

	}

	vector<int>::iterator itr = result.begin();
	    while(itr!=result.end())
	    {
	        cout<<(*itr);
	        itr++;
	    }
	    cout<<'\n';

    vector<int>::reverse_iterator ritr = result.rbegin();
    for(;ritr!=result.rend();ritr++)
    {
        cout<<(*ritr);
    }
    cout<<'\n';
	}
	return 0;
}
