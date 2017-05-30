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

int main()
{
    double golden=1.61803398875;
    double start=514229;
    start=start/100000;
    //cout<<start<<endl;
    int counter=6;
    int counter2=29;
    while(counter!=1000)
    {
        start=start*golden;
        if(start>10){
            start=start/10;
            counter++;
        }
        counter2++;
    }
    cout<<start<<' '<<counter2<<endl;
}
