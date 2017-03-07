/*ID: j316chuck
PROG: bphoto
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

int BIT[100010];
int A[100010], arr[100010];
map<int, int> MP;
int N;

int sum(int index){
    int sum = 0;
    index++;
    while(index > 0){
        sum += BIT[index];
        index -= index & (-index);
    }
    return --sum;
}

void update(int index, int val){
    index++;
    while(index <= N){
        BIT[index] += val;
        index += (index & (-index));
    }
}

int main(){

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>A[i];
        arr[i] = A[i];
    }
    sort(A, A+N);
    reverse(A, A+N);

    for(int i = 0; i < N; i++){
        MP[A[i]] = i;
        update(i, 1);
    }

    /*for(int i = 0; i < N; i++){
        cout<<BIT[i]<<' ';
    }*/

    int total = 0;
    for(int i = 0; i < N; i++){
        int right = sum(MP[arr[i]]);
        int left = MP[arr[i]]-right;
        if(right > 2 * left || left > 2 * right){
            total++;
        }
        update(MP[arr[i]], -1);
    }

    cout<<total<<endl;
    return 0;

}


