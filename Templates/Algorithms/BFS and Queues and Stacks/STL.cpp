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

int main(){
    /*vector<int> myArray;
    myArray.push_back(1);
    vector<int>::iterator itr;
    itr = myArray.begin();
    int i2 = (*itr);
    itr++;*/

    string s;
    cin>>s;
    string::iterator itr;
    for(itr=s.begin(); itr!=s.end(); itr++){
        cout<<(*itr);
    }
}
