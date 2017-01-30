/*
ID: j316chuck
PROG: bphoto
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

    Rd("bphoto.in");
    Wt("bphoto.out");

    int N;
    cin>>N;
    vector<int> A(N);
    set<int> left, right;
    for(int i = 0; i < N; i++){
        cin>>A[i];
        right.insert(A[i]);
    }
    //set<int>::iterator it = right.end()-right.upper_bound(A[0]) ;
    //cout<<distance(left.upper_bound(A[1]), left.end());
    //cout<<right.upper_bound(A[0])<<endl;
    //cout<<right.upper_bound(right.begin(), right.end(), A[0])-right.begin()<<endl;
    int total = 0;
    for(int i = 0; i < N; i++){
        int r = distance(right.upper_bound(A[i]), right.end());
        int l = distance(left.upper_bound(A[i]), left.end());
        if(r > 2 * l || l > 2 * r){
            total++;
        }
        right.erase(A[i]);
        left.insert(A[i]);
    }
    cout<<total<<endl;
    return 0;
}

