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

bool arr[10003];
int main(){
    int N, L;
    cin>>N>>L;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        arr[a]=1;
    }

    int counter=0;
    for(int i=1; i<L; i++){
        int pivot=i;
        if(i>L/2){
            for(int k=L; k>i; k--){
                if(arr[k]==1){
                    if(arr[2*i-k]!=1){
                        break;
                    }
                }if(k==i+1){
                    cout<<i<<endl;
                    counter++;
                }
            }
        }else{
            for(int k=0; k<i; k++){
                if(arr[k]==1){
                    if(arr[2*i-k]!=1){
                        break;
                    }
                }if(k==i+1){
                    cout<<i<<endl;
                    counter++;
                }
            }
        }
    }
    cout<<counter<<endl;
}
