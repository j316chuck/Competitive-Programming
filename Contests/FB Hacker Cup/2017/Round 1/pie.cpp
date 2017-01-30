/*
ID: j316chuck
PROG: progress
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

    freopen("pie_progress.in", "r", stdin);
    freopen("progress2.out", "w", stdout);

    int t, n, m;
    cin>>t;
    for(int it = 0; it < t; it++){
        cin>>n>>m;
        vector< vector<int> > A;
        for(int i = 0; i < n; i++){
            vector<int> temp(m);
            for(int j = 0; j < m; j++){
                cin>>temp[j];
            }
            sort(temp.begin(), temp.end());
            for(int j = 0; j < m; j++){
                temp[j] += (2 * j + 1);
            }
            A.push_back(temp);
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            int minimum = INT_MAX, pos = -1;
            for(int j = 0; j < A.size(); j++){
                if(A[j].size() > 0 && A[j][0] < minimum){
                    minimum = A[j][0];
                    pos = j;
                }
            }
            A[pos].erase(A[pos].begin());
            total += minimum;
        }
        printf("Case #%d: %d\n", it+1, total);
    }

    return 0;

}

