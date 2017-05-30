
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
    //Wt("balancing.out");
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
    //cout<<xmin<<' '<<ymin<<' '<<xmax<<' '<<ymax<<endl;
    int xbot=xmin, xtop=xmax;
    int xmiddlepoint=-1;
    int xdiff=1000009;
    while(xbot<xtop){
        int xmid=xbot+xtop; xmid=xmid/2;
        if(xmid%2==1)
            xmid--;
        int sum=0;
        int sum2=0;
        for(int i=0; i<N; i++){
            if(myvector[i].first<xmid){
                sum++;
            }else{
                sum2++;
            }
        }
        if(sum==sum2){
            xmiddlepoint=xmid;
            break;
        }else if(sum>sum2){
            if(xdiff>sum-sum2){
                xmiddlepoint=xmid;
            }
            xtop=xmid-1;
        }else{
            if(xdiff>sum2-sum){
                xmiddlepoint=xmid;
            }
            xbot=xmid+1;
        }
        cout<<xmiddlepoint<<endl;
    }

}
