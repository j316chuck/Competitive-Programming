/*ID: j316chuck
PROG: war
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

int parent[20001];
int n;

void init(int size){
    for(int i = 0; i < 20001; i++){
        parent[i] = i;
    }
}
int findset(int x){
    return x == parent[x] ? x : parent[x] = findset(parent[x]);
}
void arefriends(int u, int v){
    (findset(u) == findset(v)) ? cout<<"1"<<endl: cout<<"0"<<endl;
}
void areenemies(int u, int v){
    int a = u+10000, b = v+10000;
    int pu = findset(u), pv = findset(v), pa = findset(a), pb = findset(b);
    (pu == pb || pv == pa) ? cout<<"1"<<endl: cout<<"0"<<endl;
}
void setfriends(int u, int v){
    int a = u+10000, b = v+10000;
    int pu = findset(u), pv = findset(v), pa = findset(a), pb = findset(b);
    if(pu == pb || pv == pa){
        cout<<-1<<endl;
        return;
    }
    parent[pu] = parent[pv];
    parent[pa] = parent[pb];
}
void setenemies(int u, int v){
    int a = u+10000, b = v+10000;
    int pu = findset(u), pv = findset(v), pa = findset(a), pb = findset(b);
    if(pu == pv){
        cout<<-1<<endl;
        return;
    }
    parent[pu] = parent[pb];
    parent[pv] = parent[pa];
}

int main(){

    //freopen("10158.in", "r", stdin);
    //Wt("10158.out");
    cin>>n;
    init(n+1);
    int c, x, y;

    while(cin>>c>>x>>y){
        if(c == 0 && x == 0 && y == 0){
            break;
        }else if(c == 1){
            setfriends(x, y);
        }else if (c == 2){
            setenemies(x, y);
        }else if (c == 3){
            arefriends(x, y);
        }else if (c == 4){
            areenemies(x, y);
        }
    }
    return 0;
}
