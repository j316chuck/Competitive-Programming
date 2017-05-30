/*ID: j316chuck
PROG:
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
#define pii pair<int, int>

using namespace std;

int main(){

    Rd("trapped.in");
    Wt("trapped.out");

    int n, b;
    cin>>n>>b;
    vector< pair<int, int> > left; vector<pii> right;

    for(int i = 0; i < n; i++){
        int health, pos;
        cin>>health>>pos;
        if(pos > b){
            right.push_back(make_pair(pos, health));
        }else{
            left.push_back(make_pair(pos, health));
        }
    }
    sort(left.begin(), left.end());
    reverse(left.begin(), left.end());
    sort(right.begin(), right.end());



    vector<pii> l; vector<pii> r;
    for(int i = 0; i < right.size(); i++){
        int a = right[i].second - (right[i].first - left[0].first);
        if(a >= 0){
            r.push_back(make_pair(a, right[i].first));
        }
    }
    for(int i = 0; i < left.size(); i++){
        int a = left[i].second - (right[0].first - left[i].first);
        if(a >= 0){
            l.push_back(make_pair(a, left[i].first));
        }
    }
    if(r.size() == 0 && l.size() == 0){
        cout<<-1<<endl;
        return 0;
    }
    int res = INT_MAX;
    for(int i = 0; i < left.size(); i++){
        int d = left[0].first-left[i].first;
        for(int j = 0; j < r.size(); j++){
            r[j].first-=d;
            if(r[j].first < 0){
                r.erase(r.begin()+j);
                j--;
                continue;
            }
            int add =left[i].second - (r[j].second - left[i].first);
            if(add >= 0){
                cout<<0<<endl;
                return 0;
            }
            res = min(res, -add);
        }
        if(r.size() == 0){
            break;
        }
    }

    for(int i = 0; i < right.size(); i++){
        int d = right[i].first-right[0].first;
        for(int j = 0; j < l.size(); j++){
            l[j].first-=d;
            if(l[j].first < 0){
                l.erase(l.begin()+j);
                j--;
                continue;
            }
            int add = right[i].second - (right[i].first-l[j].second);
            if(add >= 0){
                cout<<0<<endl;
                return 0;
            }
            res = min(res, -add);
        }
        if(l.size() == 0){
            break;
        }
    }
    cout<<res<<endl;
    return 0;
    //cout<<l[0]<<' '<<r[0]<<endl;
}


