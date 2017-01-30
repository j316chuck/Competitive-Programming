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

int max_value=-1;
int value;
/*void knap(int weight, int value){

    for(int i=0; i<mygraph.size(); i++){
        if(mygraph[i].w<=weight){
            knap(weight-mygraph[i].w, value+mygraph[i].v);
        }
    }
    if(value>max_value){
        max_value=value;
    }
}*/

int mem[1000][1000];

int main(){
    freopen("Knapsack.txt", "r", stdin);
    int N, W;
    cin>>N>>W;
    for(int i=0; i<N; i++){
        knapsack a;
        cin>>a.id>>a.v>>a.w;
        mygraph.push_back(a);
    }
    /*for(int i=0; i<N; i++){
        cout<<mygraph[i].id<<mygraph[i].v<<mygraph[i].w<<endl;
    }*/
    memset(mem, -1, sizeof(mem));
    for(int i=0; i<=W; i++){
        mem[0][i]=(i/mygraph[0].w)*mygraph[0].v;
    }
    /*for(int i=1; i<W; i++){
        cout<<mem[0][i]<<' ';
    }*/
    for(int i=1; i<N; i++){
        for(int k=0; k<=W; k++){
            if(mygraph[i].w<=k)
                mem[i][k]=max(mem[i-1][k],mygraph[i].v+mem[i][k-mygraph[i].w]);
            else
                mem[i][k]=mem[i-1][k];
        }
    }
    for(int i=0; i<N; i++){
        for(int k=0; k<=W; k++){
            cout<<mem[i][k]<<' ';
        }
        cout<<endl;
    }
    //knap(W, 0);
    //cout<<max_value<<endl;
}
