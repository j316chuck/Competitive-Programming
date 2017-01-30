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
#define MAX 1001
using namespace std;

int mem[1700];
int used[50];

int N, total;

void Recurse(int sum, int arr[], int prev){
    if(sum == (N*(N+1)/4)){
        for(int i = 0; i < 10; i++){
            if(arr[i]!=0){
                cout<<i<<' ';
            }
        }cout<<endl;
        total += 1;
        return ;
    }else if(sum > (N*(N+1)/4)){
        return;
    }
    int total = 0;
    for(int i = prev + 1; i <= N; i++){
        if(used[i] == 0){
            used[i] = 1;
            Recurse(sum + i, used, i);
            used[i] = 0;
        }
    }
}

int main(){
    freopen("subset.in", "r", stdin);
    //freopen("subset.out", "w", stdout);

    memset(mem, -1, sizeof(mem));
    scanf("%d ", &N);

    if((N*(N+1))/2 % 2 == 1){
        printf("0 \n");
    }else{
        Recurse(0, used, 0);
        cout<<total<<endl;
    }
}

