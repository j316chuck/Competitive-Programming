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

vector< vector<int> > mygraph;
int n;
int maximum=0;
void Recurse(int a, int sum, int pos){
    if(a!=n-1){
        a+=1;
        sum+=mygraph[a][pos];
        Recurse(a,sum, pos);
        sum-=mygraph[a][pos];
        sum+=mygraph[a][pos+1];
        Recurse(a,sum, pos+1);
    }else{
        sum+=mygraph[a][pos];
        maximum=max(maximum, sum);
        sum-=mygraph[a][pos];
        sum+=mygraph[a][pos+1];
        maximum=max(maximum, sum);
        cout<<maximum<<endl;
        return;
    }
}

int main()
{
    Rd("input.txt");
    cin>>n;
    for(int i=0; i<n; i++){
        vector<int> random;
        for(int k=0; k<=i; k++){
            int a;
            cin>>a;
            random.push_back(a);
        }
        mygraph.push_back(random);
    }
    /*for(int i=0; i<n; i++){
        for(int k=0; k<=i; k++){
            cout<<mygraph[i][k]<<' ';
        }
        cout<<endl;
    }*/
    Recurse(0,0,0);
    cout<<maximum<<endl;
}
