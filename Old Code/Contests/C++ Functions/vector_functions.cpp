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
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);
    foo.swap(bar);

    //vector values are switched
//swap vector values
    swap(foo[0], foo[2]);
    cout<<foo[0];
    //insert
    http://www.cplusplus.com/reference/vector/vector/insert/
    //erase
    http://www.cplusplus.com/reference/vector/vector/erase/
}
