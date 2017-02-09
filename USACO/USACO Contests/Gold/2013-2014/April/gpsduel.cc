/*
ID: peiqistar1
PROG: duelgps
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
#define NOPATH 1000000000

using namespace std;

class pp{
public:
    int v, w;
    bool operator < (const pp & a) const{
        return (w > a.w); //sort from low to high
    }
};

int main(){

	Rd("gpsduel.in");
	Wt("gpsduel.out");

	int N, M;
	cin>>N>>M;

	vector<int> G[N+1];
	vector<pp> P[N+1];
	vector<pp> Q[N+1];
	for(int i = 0; i < M; i++){
		int a, b, p, q;
		cin>>a>>b>>p>>q;
		pp ei; ei.v = a; ei.w = q;
		Q[b].push_back(ei);
		ei.w = p;
		P[b].push_back(ei);
		G[a].push_back(b);
	}

	priority_queue<pp> pq;
	pp ei; ei.v = N; ei.w = 0;
	pq.push(ei);
	vector<int> D1(N+1, NOPATH);
	vector<int> P1(N+1, -1);
	D1[N] = 0;
	int u, v, w;
	while(!pq.empty()){
		u = pq.top().v;
		pq.pop();
		for(int i = 0; i < Q[u].size(); i++){
			w = Q[u][i].w;
			v = Q[u][i].v;
			if(D1[u] + w < D1[v]){
				D1[v]= D1[u] + w;
				P1[v] = u;
				pp ai;
				ai.v = v; ai.w = D1[v];
				pq.push(ai);
			}
		}
	}
	/*for(int i = 1; i <= N; i++)
		cout<<D1[i]<<' '<<P;
	cout<<endl;*/

	while(!pq.empty()) pq.pop();
	ei.v = N; ei.w = 0;
	pq.push(ei);
	vector<int> D2(N+1, NOPATH);
	vector<int> P2(N+1, -1);
	D2[N] = 0;
	while(!pq.empty()){
		u = pq.top().v;
		pq.pop();
		for(int i = 0; i < P[u].size(); i++){
			w = P[u][i].w;
			v = P[u][i].v;
			if(D2[u] + w < D2[v]){
				D2[v]= D2[u] + w;
				P2[v] = u;
				pp ai;
				ai.v = v; ai.w = D2[v];
				pq.push(ai);
			}
		}
	}

	while(!pq.empty()) pq.pop();
	vector<int> dist(N+1, NOPATH);
	dist[1] = 0;
	ei.v = 1; ei.w = 0;
	pq.push(ei);
	while(!pq.empty()){
		u = pq.top().v;
		pq.pop();
		for(int i = 0; i < G[u].size(); i++){
			v = G[u][i];
			w = 0;
			if(P1[u] != v) w++;
			if(P2[u] != v) w++;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pp ai;
				ai.v = v; ai.w = dist[v];
				pq.push(ai);
			}
		}
	}

	cout<<dist[N]<<endl;
}