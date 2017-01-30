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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

class knapsack{
public:
    int id;
    int v;
    int w;
};
vector<knapsack> mygraph;
int max_value;
int mem[10000];
void Recurse(int W, int value){
   for(int i=0; i<mygraph.size(); i++){
        if(W-mygraph[i].w>=0)
            Recurse(W-mygraph[i].w, mygraph[i].v+value);
        else{
            max_value=max(max_value, value);
            return;
        }
   }
}
int main(){
    freopen("Knapsack.txt", "r", stdin);
    int N, W;
    cin>>N>>W;
    for(int i=0; i<N; i++){
        knapsack a;
        cin>>a.id>>a.v>>a.w;
        mygraph.push_back(a);
    }
    Recurse(W, 0);
    cout<<max_value<<endl;
}
