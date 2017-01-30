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

int main(){
    int n, t;
    cin>>n>>t;

    string res = "";
    /*if(n == 1 && t == 10){
        cout<<-1<<endl;
    }else if(t == 1){
        for(int i = 0; i < n; i++)
            res+='1';
        cout<<res<<endl;
    }else if (t == 5 || t == 10){
        if(n == 1 && t == 5)
            cout<<5<<endl;
        for(int i = 0; i < n-1; i++){
            res+='1';
        }res+='0';
        cout<<res<<endl;
    }else if(t == 2|| t == 4|| t == 8){
        res+='8';
        for(int i = 0; i < n-1; i++){
            res+='0';
        }cout<<res<<endl;
    }
    else if( t == 3|| t== 9){
        for(int i = 0; i < n; i++){
            res+='9';
        }cout<<res<<endl;
    }else if(t == 6){
        for(int i = 0; i < n-1; i++){
            res+='9';
        }res+='6';
        cout<<res<<endl;
    }else{
        res+='7';
        for(int i = 0; i < n-1; i++){
            res+='0';
        }cout<<res<<endl;
    }*/
    if(n == 1 && t == 10){
        res = "-1";
        //cout<<-1<<endl;
    }else if(t == 10){
        res+='1';
        for(int i = 0; i < n-1; i++){
            res+='0';
        }//cout<<res<<endl;
    }else{
        res+=(t+'0');
        for(int i = 0; i < n-1; i++){
            res+='0';
        }//cout<<res<<endl;
    }
    cout<<res<<endl;
}
