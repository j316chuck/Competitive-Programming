/*
ID: peiqistar1
PROG: StudyDijkstra
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

class pp
{
public:
	int v;
	int w;

	bool operator < (const pp &a) const
	{
		return (w > a.w);   // sort from low to high
	}
};

int main (int argc, char ** argv)
{
	Rd("dij.in");

    priority_queue<pp> Q;
    int n;
    cin>>n;
    vector< pp > G[n+1]; // store each vertex edges
    int e,u,v,w;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        pp ei;
        ei.v = v;
        ei.w = w;
        G[u].push_back(ei);
    }
    int s;
    cin>>s;
    int d[n+1];
    for(int i=1;i<=n;i++)
    {
        d[i] = 999;
    }
    d[s] = 0;
    pp ei;
    ei.v = s;
    ei.w = d[s];
    Q.push(ei);
    while(!Q.empty())
    {
        u = Q.top().v;
        cout << "current:"<<u<<endl;
        Q.pop();
        int size = G[u].size();
        for(int i = 0 ; i < size ; i++)
        {
            v = G[u][i].v;
            w = G[u][i].w;
            cout<<"  v:"<<v<<" w:"<<w<<endl;
            cout<<"  d[v]:" << d[v] << " d[u]+w:" << d[u]+w << endl;
            if(d[v] > d[u] + w)
            {
            	cout << "    update: " << v << endl;
                d[v] = d[u] + w;
                cout << "       new dis for "<<v<<" is"<<d[v]<<endl;
				pp ei;
                ei.v = v;
                ei.w = d[v];
                Q.push(ei);
            }
        }
        cout<<"complete."<<endl;
        }
    for(int i=1; i<=n; i++)
    	printf("Node %d, min weight = %d\n", i, d[i]);
    return 0;
}


