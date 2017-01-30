/*
ID: j316chuck
PROG: stampede January 2016
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

using namespace std;

int main(){
    Rd("stampede.in");
    Wt("stampede.out");
    int N;
    cin>>N;
    vector < pair<int, pair<int, int> > > A;
    set<int> st;
    for(int i = 0; i < N; i++){
        int x, y, r;
        cin>>x>>y>>r;
        A.push_back(make_pair(y, make_pair((-1-x)*r, -r*x)));
        st.insert(-1*r*x);
        st.insert((-1-x)*r);
    }
    sort(A.begin(), A.end());
    int res = 0;
    for(int i = 0; i < A.size(); i++){
        auto it = st.lower_bound(A[i].second.first);
        auto pt = st.lower_bound(A[i].second.second);
        if(it!=pt){
            res++;
            st.erase(it, pt);
        }
    }
    cout<<res<<endl;
}
