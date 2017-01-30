/*
ID: j316chuck
PROG: progress
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

using namespace std;

int t, n, w;
vector<int> items;
int trip;

int rem(int a){
    if(a >= 25){
        return 2;
    }else if(a >= 17){
        return 3;
    }else if(a >= 13){
        return 4;
    }else if(a >= 10){
        return 5;
    }else if(a >= 9){
        return 6;
    }else if(a >= 8){
        return 7;
    }else if(a >= 7){
        return 8;
    }else if(a >= 6){
        return 9;
    }else if(a >= 5){
        return 10;
    }else if(a >= 4){
        return 13;
    }else if(a >= 3){
        return 17;
    }else if(a >= 2){
        return 25;
    }else if(a == 1){
        return 50;
    }
}

int main(){

    freopen("lazy_loading.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n;
        trip = 0; items.clear();

        for(int k = 0; k < n; k++){
            cin>>w;
            if(w >= 50){
                trip++;
            }else{
                items.push_back(w);
            }
        }
        sort(items.begin(), items.end());
        reverse(items.begin(), items.end());
        while(items.size() > 0 && items.size() >= rem(items[0])){
            int a = rem(items[0])-1;
            items.erase(items.begin());
            for(int i = 0; i < a; i++){
                items.pop_back();
            }
            trip++;
        }
        printf("Case #%d: %d\n", i+1, trip);
    }

    return 0;

}

