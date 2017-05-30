/*ID: j316chuck
PROG: lightsout
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

    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);

    int n;
    cin>>n;
    vector< pair<int, int> > A;

    for(int i = 0; i < n; i++){
        pair<int, int> a; cin>>a.first>>a.second;
        A.push_back(a);
    }

    vector<int> S(1,0);
    for(int i = 0; i < n; i++){
        int j = (i+1) % n;
        int k = (i+2) % n;
        S.push_back(abs(A[i].first-A[j].first) +
                    abs(A[i].second-A[j].second));
        if((A[i].first-A[j].first)*(A[k].second-A[j].second)-
           (A[i].second-A[j].second) * (A[k].first-A[j].first) > 0){
            S.push_back(-1);
        }else{
            S.push_back(-2);
        }
    }

    int mem[210];
    mem[0] = 0;
    S.back() = 0;

    for(int i = 1; i < n; i++){
        mem[i] = mem[i-1] + S[2 * i - 1];
    }
    mem[n] = mem[n-1] + S[2 * n - 1];
    for(int i = 0; i < n; i++){
        mem[i] = min(mem[n] - mem[i], mem[i]);
    }
    mem[n] = 0;

    multiset< vector<int> > st;
    for(int i = 0; i < S.size(); i+=2){
        for(int k = 1; k + i <= S.size(); k+=2){
            st.insert(vector<int>(S.begin() + i, S.begin() + i + k));
        }
    }


    int result = 0;

    for(int i = 1; i < n; i++){
        int cost = 0;
        int ln;
        vector<int> v;
        v.push_back(S[i * 2]);
        for(ln = i * 2 + 2; ln < S.size(); ln+=2){
            if(st.count(v) == 1){
                break;
            }
            v.push_back(S[ln - 1]);
            v.push_back(S[ln]);
            cost+=S[ln-1];
        }
        //cout<<cost + mem[ln/2-1] - mem[i]<<' '<<endl;
        result = max(result, cost + mem[(ln-2)/2]-mem[i]);
    }
    /*for (int i = 2; i + 2 < S.size(); i += 2) {
        int ln;
        int cost = 0;
        for (ln = 1; ; ln += 2) {
              if (st.count(vector<int>(S.begin() + i, S.begin() + i + ln)) == 1) {
                break;
              }
              cost += S[i + ln];
        }
        cout<<cost + mem[(i + ln) / 2] - mem[i / 2]<<endl;
        result = max(result, cost + mem[(i + ln) / 2] - mem[i / 2]);
        cout<<result<<endl;
      }*/


    printf("%d\n", result);
    /*for(int i = 0; i < S.size(); i++){
        cout<<S[i]<<' ';
    }*/
}
