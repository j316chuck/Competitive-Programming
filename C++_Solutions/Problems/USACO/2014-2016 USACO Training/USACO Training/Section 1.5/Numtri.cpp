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
int N;
vector< vector<int> > graph;
int total =0;
int maximum=0;
void Recursion(int i,int j, int sum)
{
    if(i<N)
    {
        sum+=graph[i][j];
        //cout<<total<<' '<<i<<' '<<j<<endl;
        Recursion(i+1,j, sum);
        Recursion(i+1,j+1,sum);
    }
    else
    {

        if(sum>maximum)
            maximum=sum;
    }


}
int main()
{

    Rd("numtri.in");
    //Wt("numtri.out");
    cin>>N;
    for(int i=0; i <N; i++)
    {
        vector<int> random;
        for(int j=0; j<=i; j++)
        {
            int a;
            cin>>a;
            random.push_back(a);
        }
        graph.push_back(random);
    }
    /*for(int i=0; i <N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout<<graph[i][j]<<' '<<i<<' '<<j<<' ';
        }
        cout<<endl;
    }*/

    Recursion(0,0,0);
    cout<<maximum<<endl;

}
