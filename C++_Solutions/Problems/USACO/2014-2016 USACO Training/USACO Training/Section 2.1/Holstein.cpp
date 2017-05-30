/*
ID: j316chuck
PROG: holstein
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
#define MAX 1001
using namespace std;

vector<int> target;
vector< vector<int> > feed;


int V;
int G;

bool check(){
    for(int i=0; i <target.size(); i++){
        if(target[i]>0)
            return false;
    }
    return true;
}
int moves=999;
void solve(int position, int counter){

    for(int i=position; i<G; i++){
        for(int k=0; k <V; k++){
            target[k]-=feed[i][k];
        }
        counter++;
        if(check()==true){
            moves=min(counter,moves);
            return;
        }
        if(i>position){
            solve(i,counter);
        }
        for(int k=0; k<V; k++){
            target[k]+=feed[i][k];
        }
        counter--;
    }
}
int main()
{
    Rd("Holstein.in");
    //Wt("Holstein.out");
    for(int i=0; i<V; i++){
        int a;
        cin>>a;
        target.push_back(a);
    }
    cin>>G;
    for(int i=0; i<G; i++){
        vector<int> random;
        for(int k=0; k<V; k++){
            int a;
            cin>>a;
            random.push_back(a);
        }
        feed.push_back(random);
    }
    solve(0,0);
    cout<<moves<<endl;
}
