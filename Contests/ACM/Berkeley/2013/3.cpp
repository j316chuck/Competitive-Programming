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
//#include <contest.h>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int prev[101];
int N, term;

int main(){

    freopen("3.in", "r", stdin);
    while(cin>>N){
        int sequence[101][101];
        for(int i = 0; i < N; i++){
            cin>>sequence[0][i];
        }
        cin>>term;
        if(term <= N){
            printf("Term %d of the sequence is %d\n", term , sequence[term-1]);
        }
        else{
            for(int i = 1; i < N; i++){
                for(int j = 0; j < N-i; j++){
                    sequence[i][j] = sequence[i-1][j+1]-sequence[i-1][j];
                }
            }
            for(int i = 0; i < N; i++){
                prev[i] = sequence[N-1-i][i];
            }
            for(int i = 0; i < term - N; i++){
                for(int k = 1; k < N; k++){
                    prev[k] += prev[k-1];
                }
            }
           printf("Term %d of the sequence is %d\n", term , prev[N-1]);
        }
    }
    exit(0);
}
