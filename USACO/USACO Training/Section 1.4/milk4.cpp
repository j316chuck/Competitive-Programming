/*
ID: j316chuck
PROG: milk3
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

int A, B, C;

int visited[21][21];
vector<int> result;
void dfs(int a, int b){
    int c;
    c=C-a-b;
    if(visited[a][b]==1)
        return;
    visited[a][b]=1;
    if(a==0)
        result.push_back(c);

    if(c>A-a)dfs(A,b);//c->a
    else dfs(C-b,b);

    if(a>C-c)dfs(a-(C-c),b);//a->c
    else dfs(0,b);

    if(c>B-b)dfs(a,B);//c->b
    else dfs(a,C-a);

    if(b>C-c)dfs(a,b-(C-c));//b->c
    else dfs(a,0);

    if(a>B-b)dfs(a-(B-b),B);//a->b
    else dfs(0,b+a);

    if(b>A-a) dfs(A, b-(A-a));//b->a
    else dfs(a+b,0);
}
int main(){

    Rd("milk3.in");
    Wt("milk3.out");


    cin>>A>>B>>C;

    dfs(0,0);
    sort(result.begin(), result.end());
    for(int i=0; i <result.size(); i++){
        if(i!=result.size()-1)
        cout<<result[i]<<' ';
        else
            cout<<result[i]<<endl;
    }
    //cout<<endl;
}

