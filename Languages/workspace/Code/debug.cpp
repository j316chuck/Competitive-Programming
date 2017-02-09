/*ID: j316chuck
PROG: poj_1308
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
#define pii pair<int, int>

using namespace std;

int main(){

	Rd("input.in");
	int u, v;
	vector<pii> G;
	map<int, vector<int> > tree;
	map<int, int> parent;
	int counter = 0;

	while(1){
		cin>>u>>v;
		if(u == -1 && v == -1){
			break;
		}
		counter++;
		G.clear();
		tree.clear();
		G.push_back(make_pair(u, v));
		parent.clear();
		while(1){
			if(u == 0 && v == 0){
				G.pop_back();
				for(int i = 0; i < G.size(); i++){
					if(tree.find(G[i].first) == tree.end()){
						tree.insert(make_pair(G[i].first, vector<int>()));
					}
					tree[G[i].first].push_back(G[i].second);
					if(!parent[G[i].second]){
						parent.insert(make_pair(G[i].second, 0));
					}if(!parent[G[i].first]){
						parent.insert(make_pair(G[i].first, 0));
					}
					parent[G[i].second]++;
				}
				int start = -1;
				bool b;
				for(map<int, int>::iterator it = parent.begin(); it != parent.end(); it++){
					if(it->second == 0){
						if(start == -1){
							start == it->first;
						}else{
							b = true; //cycle
						}
					}
				}
				if(start == -1 || b){
					printf("Case %d is not a tree.\n", counter); //no root;
					break;
				}
				queue<int> q;
				set<int> visit;
				q.push(start);
				while(!q.empty()){
					int u = q.front();
					if(visit.find(u) != visit.end()){
						printf("Case %d is not a tree.\n", counter); //no root;
						break;
					}
					q.pop();
					visit.insert(u);
					if(tree.find(u) == tree.end())
						continue;
					for(int i = 0; i < tree[u].size(); i++){
						int v = tree[u][i];
						q.push(v);
					}
				}
				printf("Case %d is a tree.\n", counter); //no root;
				break;
			}
			cin>>u>>v;
			G.push_back(make_pair(u, v));
		}
	}
}
