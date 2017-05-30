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

int main(){

    Rd("ABCDEF.in");
    int N;
    cin>>N;
    int A[101];
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    vector<long long> B;
    vector<long long> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                B.push_back(A[i]*A[j]+ A[k]);
                if(A[k] != 0){
                    D.push_back((A[i]+A[j])*A[k]);
                }
            }
        }
    }
    sort(B.begin(), B.end());
    sort(D.begin(), D.end());

    int total = 0;
    for(int i = 0; i < B.size(); i++){
        //auto it = lower_bound(D.begin(), D.end(), B[i]);
        //auto et = upper_bound(D.begin(), D.end(), B[i]);
        //total += (et-it);
        int upper = -1, lower = -1;
        for(int k = D.size(); k >=1; k/=2){
            while(upper+k < D.size() && D[upper+k] <=  B[i]){
                upper+=k;
            }
            while(lower+k < D.size() && D[lower+k] < B[i]){
                lower+=k;
            }
        }
        total+=(upper-lower);
    }
    cout<<total<<endl;
}
