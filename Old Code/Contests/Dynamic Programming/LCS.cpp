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

int check[1000];
int lis[1000];
int mem[1000];
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;

    for(int i=0; i<s1.size(); i++){
        for(int k=0; k<s2.size(); k++){
            if(s1[i]==s2[k]&&check[k]!=1){
                lis[i]=k;
                check[k]=1;
                break;
            }if(k==s2.size()-1){
                lis[i]=-1;
            }
        }
    }

    /*for(int i=0; i<s1.size(); i++){
        cout<<lis[i]<<endl;
    }*/
    int N=s1.size();
    for(int i=0; i<N; i++){
        if(lis[i]!=-1)
            mem[i]=1;
        else
            mem[i]=0;
    }
    for(int i=N-2; i>=0; i--){
        for(int k=i+1; k<N; k++){
            if(lis[i]==-1){
                mem[i]=mem[i+1];
                break;
            }else if(lis[i]<lis[k]){
                mem[i]=max(mem[i], mem[k]+1);
            }
        }
    }
    //sort(mem, mem+N);
    //cout<<mem[N-1]<<endl;
    for(int i=0; i<N; i++){
        cout<<mem[i]<<' ';
    }
}
