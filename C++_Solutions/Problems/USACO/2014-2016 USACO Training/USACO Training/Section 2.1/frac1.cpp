/*
ID: j316chuck
PROG: frac1
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

class two{
    public:
    string frac;
    float dec;
    bool operator<(const two& a) const
    {return dec<a.dec; }
};
//bool myComp(const double&a, const double&b) { if (a>b) return true;}
bool commondiv(int a, int b){
    for(int i=2; i<=a&&i<=b; i++){
        if(a%i==0&&b%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    Rd("frac1.in");
    Wt("frac1.out");
    vector<two> mygraph;

    int N;
    cin>>N;
    for(int i=N; i>=1; i--){
        for(int k=1; k<i; k++){
            if(commondiv(i,k)==true){
            two a;
            a.dec=float(k)/float(i);
            ostringstream convert;
            convert<<k;
            string r=convert.str();
            a.frac+=r;
            a.frac+="/";
            ostringstream revert;
            revert<<i;
            string r2=revert.str();
            a.frac+=r2;
            mygraph.push_back(a);
            }
        }
    }
    two a;
    a.dec=0;
    a.frac+=0+'0';
    a.frac+="/";
    a.frac+=1+'0';
    mygraph.push_back(a);
    two b;
    b.dec=1;
    b.frac+=1+'0';
    b.frac+="/";
    b.frac+=1+'0';
    mygraph.push_back(b);
    //mygraph.push_back
    sort(mygraph.begin(), mygraph.end());
    for(int i=0; i <mygraph.size(); i++){
        cout<<mygraph[i].frac<<endl;
    }

}
