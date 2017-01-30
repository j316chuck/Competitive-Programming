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
    string n, m;
    cin>>n>>m;
    int N=n.size();
    int M=m.size();
    int array[N+1][M+1];
    string s="";
    for(int i=0; i<=N; i++){
        for(int k=0; k<=M; k++){
            if(i==0||k==0){
                array[i][k]=0;
            }else if(n[i-1]==m[k-1]){
                array[i][k]=array[i-1][k-1]+1;
                s+=n[i-1];
            }
            else{
                array[i][k]=max(array[i-1][k], array[i][k-1]);
            }
        }
    }
    /*for(int i=0; i<=N; i++){
        for(int k=0; k<=M; k++){
            cout<<array[i][k]<<" ";
        }
        cout<<endl;
    }*/
    cout<<array[N][M]<<endl;
    cout<<s<<endl;
}

