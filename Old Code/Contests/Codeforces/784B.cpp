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
    int two, three, five, six;
    cin>>two>>three>>five>>six;
    int counter = min(two, min(five, six));
    if(counter == two){
        cout<<256*two<<endl;
    }else{
        two = two-counter;
        cout<<counter * 256 + (min(three, two) * 32)<<endl;
    }
}
