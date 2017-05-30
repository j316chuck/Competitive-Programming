/*
ID: j316chuck
PROG: holstein
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

int V, G;
vector<int> goal;
vector< vector<int> > mygraph;
vector<int> result;

void we(vector<int> &v){
        for(int i=0; i <v.size(); i++){
            cout<<v[i];
        }
}
int main()
{
    for(int i=1; i<10; i++)
        goal.push_back(i);
    we(goal);
}
