/*
ID: j316chuck
PROG: numtri
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

vector< vector<int> > mygraph;
vector< vector<int> > maximum;
int main()
{
    Rd("numtri.in");
    Wt("numtri.out");

    int N;
    cin>>N;

    for(int i=0; i <N; i++)
    {
        vector<int> b;
        vector<int> c;
        for(int k=0; k<=i; k++){
            int a;
            cin>>a;
            b.push_back(a);
            c.push_back(0);
        }
        mygraph.push_back(b);
        maximum.push_back(c);
    }

    /*for(int i=0; i <N;i++){
        for(int k=0; k <=i; k++){
            cout<<mygraph[i][k]<<' ';
        }
        cout<<endl;
    }*/
    for(int i=0; i<N; i++){
        maximum[N-1][i]=mygraph[N-1][i];
        //cout<<maximum[N-1][i]<<' ';
    }
    for(int i=N-2; i>=0;i--){
        for(int k=0; k <=i; k++){
            maximum[i][k]=mygraph[i][k]+max(maximum[i+1][k],maximum[i+1][k+1]);
        }
    }
    cout<<maximum[0][0]<<endl;
}
