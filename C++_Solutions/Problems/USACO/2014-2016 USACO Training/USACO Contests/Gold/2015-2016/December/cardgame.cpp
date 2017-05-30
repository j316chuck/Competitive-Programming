
/*
ID: j316chuck
PROG:
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

bool b[100001];

int main(){

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n;
    cin>>n;
    int a;
    vector<int> first;
    for(int i = 0; i < n/2; i++){
        cin>>a;
        first.push_back(a);
        b[a] = true;
    }
    vector<int> second;
    for(int i = 0; i < n/2; i++){
        cin>>a;
        second.push_back(a);
        b[a] = true;
    }
    vector<int> arr;
    for(int i = 1; i <= 2*n; i++){
        if(b[i] == false){
            arr.push_back(i);
        }
    }
    vector<int> small;
    for(int i = 0; i < n/2; i++){
        small.push_back(arr[i]);
    }
    vector<int> big;
    for(int i = n/2; i < arr.size(); i++){
        big.push_back(arr[i]);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());


    int counter = 0;
    int pos = big.size()-1;
    for(int i = first.size()-1; i >= 0; i--){
        if(big[pos] > first[i]){
            counter++;
            pos--;
        }
    }
    //cout<<counter<<endl;
    pos = 0;
    for(int i = 0; i < second.size(); i++){
        if(small[pos] < second[i]){
            counter++;
            pos++;
        }
    }
    cout<<counter<<endl;

}
