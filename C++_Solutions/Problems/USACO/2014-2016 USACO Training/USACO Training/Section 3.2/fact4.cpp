/*ID: j316chuck
PROG: fact4
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


int main(){

    Rd("fact4.in");
    Wt("fact4.out");

    int N;
    cin>>N;

    int counter = 1;
    long long value = 1;
    while(counter <= N){
        value *= counter;
        if(value % 10 == 0){
            value = value/10;
        }
        value = value % 100000000;
        counter++;
    }
    while(value%10 == 0){
        value = value/10;
    }
    cout<<value%10<<endl;
}

