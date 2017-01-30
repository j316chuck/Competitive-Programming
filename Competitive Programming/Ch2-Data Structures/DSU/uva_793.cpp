/*ID: j316chuck
PROG: checklist
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

//vector<int> pset(1000);
//vector<int> rank(1000);
vector<int> pset(1000);
void initset(int size){
    pset.resize(size);
    //rank.resize(size);
    for(int i = 0; i < size+1; i++){
        pset[i] = i;
        //rank[i] = 1;
    }
}
int findset(int x){
    if(x!=pset[x]){
        pset[x] = findset(pset[x]);
    }
    return pset[x];
}
void unionset(int i, int j){
   pset[findset(i)] = pset[findset(j)];
}

int main(){

    freopen("793.in", "r", stdin);
    //freopen("794.out", "w", stdout);
    int t, n;
    scanf("%d", &t);
    string s;
    char c; int x, y;
    for(int i = 0; i < t; i++){
        scanf("\n%d\n", &n);
        initset(n);
        int good = 0, bad = 0;
        while(1){
            if(!getline(cin, s) || s.empty()){
                break;
            }
            sscanf(s.c_str(), "%c %d %d", &c, &x, &y);
            //cout<<c<<x<<y<<endl;
            if(c == 'c'){
                unionset(x, y);
            }else{
                if(findset(x) == findset(y)){
                    good++;
                }else{
                    bad++;
                }
                //findset(x) == findset(y) ? good++ : bad++;
            }
        }
        if(i!=0) printf("\n");
        printf("%d,%d\n", good, bad);
    }
}
