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

bool Recurse(int num, int N, int mod){
    if(num>N)
        return false;
    else if(num==N)
        return true;
    else if(num<N){
        int sum=0;
        for(int i=1; i<=mod;i=i*2){
            if(mod%i==0){
                sum++;
            }else{
                break;
            }
        }
        sum+=2;
        num+=sum;
        mod++;
        Recurse(num, N, mod);
    }
}
int main(){
    //Rd("moo.in");
    //Wt("moo.out");
    int N;
    cin>>N;
    int num=1;
    bool s=Recurse(num, N, 1);
    if(s==true)
        cout<<"m"<<endl;
    else
        cout<<"o"<<endl;
}
