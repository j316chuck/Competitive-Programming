/*
ID: j316chuck
PROG: cowdance
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

int N, T;
int arr[10001];
bool time(int K){
    if(K >= N){
        return true;
    }
    multiset<int> S;
    for(int i = 0; i < K; i++){
        S.insert(arr[i]);
    }

    int time = 0;
    for(int i = 0; i < N; i++){
        time += ((*S.begin())-time) > 0 ? ((*S.begin())-time): 0;
        S.erase(S.begin());
        if(i+K < N){
            S.insert(arr[i+K]+time);
        }
    }
    return time <= T;
}

int main(){

    Rd("cowdance.in");
    Wt("cowdance.out");

    cin>>N>>T;

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    int p = 0;
    for(int i = N; i >= 1; i /= 2){
        while(!time(p+i)){
            p+=i;
        }
    }
    if(p == N){
        cout<<N<<endl;
        return 0;
    }
    cout<<p+1<<endl;
    //int lo = 1, hi = N, mid;
    /*while(hi-lo > 5){
        mid = (lo + hi)/2;
        if(time(mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    while(lo!=hi){
        if(time(lo)){
            cout<<lo<<endl;
            return 0;
        }
        lo++;
    }*/
}
