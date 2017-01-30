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

int main(){

    //freopen("734A.in", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            counter++;
        }
    }
    if(n%2 == 1){
        if(counter > n/2){
            cout<<"Anton"<<endl;
        }else{
            cout<<"Danik"<<endl;
        }
    }else{
        if(counter > n/2 ){
            cout<<"Anton"<<endl;
        }else if(counter == n/2){
            cout<<"Friendship"<<endl;
        }else{
            cout<<"Danik"<<endl;
        }
    }
    return 0;
}
