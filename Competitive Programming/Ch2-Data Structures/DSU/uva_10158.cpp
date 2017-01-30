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

vector<int> parent(50);
int country;
void init(int size){
    parent.resize(size);
    for(int i = 0; i < size; i++){
        parent[i] = i;
    }
}
int findset(int x){
    if(x == -1 || x == -2 || x == parent[x]){
        return x;
    }
    return parent[x] = findset(parent[x]);
}
bool arefriends(int u, int v){
    return (findset(u) == findset(v)) ? true: false;
}
bool areenemies(int u, int v){
    return (findset(u)+findset(v) == -3) ? true: false;
}
bool setfriends(int u, int v){
    int pu = findset(u);
    int pv = findset(v);
    if(pu < 0 && pv < 0 && pu != pv){
        return false;
    }else if (pu < 0 && pv > 0){
        parent[pv] = pu;
    }else if(pv < 0 && pu > 0){
        parent[pu] = pv;
    }else{
        parent[pu] = parent[pv] = -1;
    }
    return true;
}
bool setenemies(int u, int v){
    int pu = findset(u);
    int pv = findset(v);
    if(pu == pv){
        return false;
    }else if(pu < 0 && pv > 0){
        (pu == -1) ? parent[pv] = -2: parent[pv] = -1;
    }else if(pv < 0 && pu > 0){
        (pv == -1) ? parent[pu] = -2: parent[pu] = -1;
    }else{
        parent[pu] = -1;
        parent[pv] = -2;
    }
    return true;
}

int main(){

    freopen("10158.in", "r", stdin);
    //Wt("10158.out");
    int n;
    cin>>n;
    init(n+1);
    int c, x, y;
    while(cin>>c>>x>>y){
        country = -1;
        if(c == 0 && x == 0 && y == 0){
            break;
        }else if(c == 1){
            setfriends(x, y) ? : cout<<-1<<endl;
        }else if (c == 2){
            setenemies(x, y) ? : cout<<-1<<endl;
        }else if (c == 3){
            arefriends(x, y) ? cout<<1<<endl : cout<<0<<endl;
        }else if (c == 4){
            areenemies(x, y) ? cout<<1<<endl : cout<<0<<endl;
        }
    }
    return 0;
}
