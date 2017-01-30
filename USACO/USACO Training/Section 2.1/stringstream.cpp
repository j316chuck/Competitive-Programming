/*
ID: j316chuck
PROG: sort3
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

vector<int> mygraph;
int main()
{
    //stringstream ss;
    /*int Number = 123;       // number to be converted to a string

    string Result;          // string which will contain the result

    ostringstream convert;   // stream used for the conversion

    convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

    Result = convert.str(); // set 'Result' to the contents of the stream
    cout<<Result<<endl;*/
    for(int i=1; i<10; i++){
         mygraph.push_back(i);
    }

    string a;
    for(int i=0; i<mygraph.size(); i++){
        a+=mygraph[i]+'0';
    }
    cout<<a<<endl;


}
