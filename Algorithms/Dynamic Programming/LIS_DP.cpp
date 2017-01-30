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

vector<int> myarray;
int mem[1000];

int N;

int main(){
    freopen("LIS.in", "r", stdin);
    memset(mem,-1, sizeof(mem));
    cin>>N;
    //cout<<N<<endl;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        myarray.push_back(k);
    }
    for(int i = 0; i < N; i++)
        mem[i] = 1;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(myarray[j] < myarray[i] && mem[j]+1 > mem[i]){
                mem[i] = mem[j]+1;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout<<mem[i]<<' ';
    }
    cout<<"The LIS is : "<<mem[N-1];
}

