/*
ID: j316chuck
PROG: ariprog
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

int N, M;

bitset<125001> good;
pair<int, int> ans[10000];

bool comp (pair<int, int> a, pair<int, int> b)
{
   if (a.second < b.second || a.second == b.second && a.first < b.first)
       return true;

   return false;
}

int main()
{
    Rd("ariprog.in");
    //Wt("ariprog.out");
    vector< pair<int, int>  > result;
    int cans=0;
    cin>>N>>M;
    int i,j,k;

    for(i=0; i<=M; i++){
        for(k=i; k <=M; k++){
            good[i*i+k*k]=1;
        }
    }

    //int value=0;

    /*for(int i=0; i <M*M; i++){
        if(good[i]==0){
            continue;
        }
        for(int k=0; k<M*M; k++){
            for(int j=0; j<N; j++){
                value=i+j*k;
                if(good[value]==0)
                    break;
                if(j==N-1){
                    pair<int, int> a;
                    a.first=j;
                    a.second=i;
                    result.push_back(a);
                }
            }
        }
    }*/
    for(i=0; i<=125000; i++){
        if(good[i]==0)
            continue;

        for(k=(125000-i)/(N-1); k>0; k--){
            for(j=1; j<N; j++){
                if(good[k*j+i]==0)
                    break;

            }
            if(j==N){
               ans[cans].first=i;
               ans[cans++].second=k;
            }

        }
    }
    sort(ans, ans+cans, comp);
    if(cans==0)
        cout<<"NONE"<<'\n';
    else{
        for(int i=0; i <cans; i++){
            cout<< ans[i].first << " " << ans[i].second << "\n";
        }
    }

}
