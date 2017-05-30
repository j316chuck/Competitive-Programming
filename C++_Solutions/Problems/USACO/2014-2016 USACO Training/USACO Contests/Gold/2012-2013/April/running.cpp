/*ID: j316chuck
PROG: running
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

int n, l, c;
int bit[100005];

void bit_init(int n){
    for(int i = 1; i <= n; i++){
        bit[i] = 0;
    }
}

void increment(int i, int n){
    for(int j = i; j <= n; j += (j & (-j))){
        bit[j]++;
    }
}

int sum(int index, int n){
    int total = 0;
    for(int i = index; i > 0; i -= (i & (-i))){
        total += bit[i];
    }
    return total;
}

class pp{
public:
    long long mod, speed, r;
};

bool cmp_speed(pp &a, pp &b){
    return a.speed < b.speed;
}

bool cmp_mod(pp &a, pp &b){
    return a.mod < b.mod;
}

int main(){

    Rd("running.in");
    //Wt("running.out");

    long long n, l, c;
    cin>>n>>l>>c;
    vector<pp> A(n);
    long long max_speed = -1;
    for(int i = 0; i < n; i++){
        cin>>A[i].speed;
        max_speed = max(max_speed, A[i].speed);
    }
    for(int i = 0; i < n; i++){
        A[i].mod = (l * c * A[i].speed) % (c * max_speed);
    }
    sort(A.begin(), A.end(), cmp_mod);
    int r = 1, b, a = 0;
    while(a < n){
        b = a;
        while(b < n && A[b].mod == A[a].mod){
            A[b].r = r;
            b++;
        }
        a = b;
        r++;
    }
    sort(A.begin(), A.end(), cmp_speed);
    bit_init(n);
    long long laps, addition, lap_sum = 0, total = 0;
    for(int i = 0; i < n; i++){
        laps = (A[i].speed * l)/ max_speed;
        addition = (laps - 1) * (long long)i - lap_sum + (long long) sum(A[i].r, n);
        //cout<<addition<<' '<<(laps-1)*i<<' '<<i<<' '<<lap_sum<<' '<<sum(A[i].r)<<endl;

        total += addition;
        lap_sum += laps;
        increment(A[i].r, n);
        /*for(int i = 1; i <= n; i++) cout<<bit[i]<<' ';
        cout<<endl;*/
    }
    cout<<total<<endl;
}




