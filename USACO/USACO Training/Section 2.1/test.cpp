/*
ID: j316chuck
PROG: numtri
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
#define MAX 1001
using namespace std;

bool commondiv(int a, int b){
    for(int i=2; i<=a&&i<=b; i++){
        if(a%i==0&&b%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    ostringstream convert;
    int N=10;
    int k=11;
    string s;
    //convert<<N;
    //s=convert.str();

   /* cout<<s<<endl;
     ostringstream revert;
    revert<<k;
    s=revert.str();
    cout<<s<<endl;*/

    s=N+"";
    cout<<s<<endl;
    //cout<<commondiv(8,17)<<endl;
}
