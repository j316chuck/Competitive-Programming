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

int N;

int Recurse(int sum, int arr[], int prev){
    if(sum < 0 ){
        return 0;
    }if(sum == 0){
        /*for(int i = 0; i < 10; i++){
            if(arr[i] == 1)
                cout<<i<<' ';
        }cout<<endl;*/
        return 1;
    }
    if(mem[sum] == -1){
        int total = 0;
        for(int i = prev + 1; i <= N; i++){
            if(arr[i] == 0){
                arr[i] = 1;
                total += Recurse(sum-i, arr, i);
                arr[i] = 0;
            }
        }
        cout<<total<<' '<<sum<<endl;
        mem[sum] = total;
        return mem[sum];
    }else{
        //cout<<sum<<' '<<mem[sum]<<endl;
        return mem[sum];
    }
}

int main(){
    freopen("subset.in", "r", stdin);
    //freopen("subset.out", "w", stdout);

    memset(mem, -1, sizeof(mem));
    scanf("%d ", &N);
    mem[0] = 1;
    int sum = N * (N+1);
    sum = sum / 2;
    if(sum % 2 == 1){
        printf("0 \n");
    }else{
        int a = Recurse(sum/2, used, 0);
        printf("%d \n", a);
    }
}
