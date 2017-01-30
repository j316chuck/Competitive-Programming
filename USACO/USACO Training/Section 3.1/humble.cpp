/*
ID: j316chuck
PROG: humble
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
#define pii pair<int, int>
using namespace std;

int K, N;
long long A[110];
long long M[100010];
long long H[100010];

int main(){

    Rd("humble.in");
    Wt("humble.out");

    cin>>K>>N;
    for(int i = 1; i <= K; i++){
        cin>>A[i];
    }
    sort(A+1, A+K+1);
    H[0] = 1;

    int counter = 1;
    while(counter!=N+1){
        int pos = -1;
        for(int i = 1; i <= K; i++){
            if(pos == -1 || H[M[i]] * A[i] < H[M[pos]]*A[pos]){
                pos = i;
            }
        }
        H[counter] = H[M[pos]]*A[pos];

        for(int i = 1; i <= K; i++){
            if(H[M[i]]*A[i] == H[counter]){
                M[i]+=1;
            }
        }
        counter++;
    }
    cout<<H[N]<<endl;

    return 0;
}
