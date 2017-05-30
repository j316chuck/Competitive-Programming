
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

int main(){
    Rd("balancing.in");
    Wt("balancing.out");
    int N;
    cin>>N;
    vector< pair<int, int> > myvector;
    int xmin=1000009, ymin=1000009, xmax=-1, ymax=-1;
    for(int i=0; i<N; i++){
        pair<int, int> a;
        cin>>a.first>>a.second;
        xmin=min(xmin, a.first);
        xmax=max(xmax, a.first);
        ymin=min(ymin, a.second);
        ymax=max(ymax, a.second);
        myvector.push_back(a);
    }
    int optimal=(N+3)/4;
    int minimum=100000000;
    bool badcondition=false;
    int start=ymin+1;
    int end=ymax;
    for(int i=xmin+1; i<xmax; i+=2){
        for(int j=ymin+1; j<ymax; j+=2){
            int q1=0, q2=0, q3=0, q4=0;
            for(int k=0; k<N; k++){
                if(myvector[k].first<i&&myvector[k].second<j){
                    q3++;
                }else if(myvector[k].first<i&&myvector[k].second>j){
                    q2++;
                }else if(myvector[k].first>i&&myvector[k].second<j){
                    q4++;
                }else{
                    q1++;
                }
            }
            int maximum=max(max(q1,q2), max(q3, q4));
            //badcondition=false;
            if(maximum<minimum)
                minimum=maximum;
        }
    }
    cout<<minimum<<endl;
}
