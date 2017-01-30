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

int t, x, y;
double p;

double dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main(){

    freopen("progress.in", "r", stdin);
    freopen("progress.out", "w", stdout);

    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>p>>x>>y;
        bool white = false;
        double AB = dist(x, y, 50, 50);
        double BC = dist(50, 50, 50, 100);
        double AC = dist(x, y, 50, 100);
        double theta =acos((AC - AB - BC)/(-2 * sqrt(AB) * sqrt(BC))) * 180/acos(-1.0);
        //cout<<AC<<" "<<AB<<" "<<BC<<" "<<(AC-AB-BC)/(-2 * sqrt(AB)*sqrt(BC))<<endl;
        //cout<<theta<<endl;
        if(x <= 50){
            theta = 360 - theta;
        }
        if(AB <= BC && theta < p * 3.6){
            printf("Case #%d: black\n", i+1);
        }else{
            printf("Case #%d: white\n", i+1);
        }
    }

    return 0;
}
