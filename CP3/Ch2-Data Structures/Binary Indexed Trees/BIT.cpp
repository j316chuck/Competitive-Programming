/*ID: j316chuck
PROG: BIT
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

int BITree[10001];

int getSum(int index){
    int sum = 0;
    index = index+1;
    while(index > 0){
        sum+=BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index, int val){
    index = index+1;
    while(index <= n){
        BITree[index]+= val;
        index += index & (-index);
    }
}

void construct(int n, int arr[]){
    for(int i = 0; i < n; i++){
        updateBIT(n, i, arr[i]);
    }
}

int main(){

    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);

    construct(n, freq);
    updateBIT(n, 3, 6);
    cout<<getSum(5)<<endl;
    //cout<<(8 & -8)<<endl;

}


