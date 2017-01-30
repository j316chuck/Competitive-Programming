/*ID: j316chuck
PROG: uva_459
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
void init(int size){
    parent.resize(size);
    for(int i = 0; i < size; i++){
        parent[i] = i;
    }
}
int findset(int i){
    return (parent[i] == i) ? i : (parent[i] = findset(parent[i]));
}
void unionset(int i, int j){
    parent[findset(i)] = findset(j);
}
bool issameset(int i, int j){
    return findset(i) == findset(j);
}

int main(){

    //freopen("459.in", "r", stdin);

    int t;
    scanf("%d\n\n", &t);
    string s;
    for(int i = 0; i < t; i++){
        getline(cin, s);
        int n = s[0] - 'A' + 1;
        init(n);
        while(1){
            if(!getline(cin, s) || s.empty()){
                break;
            }
            int u = s[0] - 'A';
            int v = s[1] - 'A';
            if(findset(u) != findset(v)){
                unionset(u, v);
                n--;
            }
        }
        if(i!=0){
            printf("\n");
        }
        printf("%d\n", n);
        /*set<int> temp;
        for(int i = 0; i <= c-'A'; i++){
            temp.insert(findset(i));
        }
        printf("%d\n\n", temp.size());*/
    }

    return 0;
}


