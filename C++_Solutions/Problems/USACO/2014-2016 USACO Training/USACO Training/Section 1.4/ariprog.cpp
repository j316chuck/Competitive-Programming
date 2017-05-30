/*
ID: j316chuck
PROG: ariprog
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
int N, M;
bool good[10000];
class two
{
public:
    int x;
    int y;
    bool operator < (const two &a) const
    {
        return y<a.y;
    }

};
/*
bool Comp (int a, int b)
{
if(a>b||a=b)
    return true;

    return false;

}

*/

int main()
{
    //Rd("ariprog.in");
    //Wt("ariprog.out");
    cin>>N>>M;

    for(int i = 0; i < M*M; i++)
    {
        for(int j = i; j < M*M; j++)
        {
            good[i*i+j*j]=true;
        }
    }
    /*for(int i = 0; i < 100; i++)
    {
        if(good[i])
        cout<<good[i]<<' '<<i<<endl;
    }*/
    vector<two> myvector;


    for(int i = 0; i < 2*M*M; i++){
        for(int k = 1; k< 2*M*M; k++){
           int total = i;
           if(good[total]==false){
               continue;
           }
           for(int j = 0; j<N-1; j++){
               total+=k;
               if(good[total]==false){
                //cout<<good[total]<<' '<<i<<' '<<k<<' '<<j<<endl;
                 break;
               }
               if(j==N-2){
                    //cout<<i<<' '<<k<<endl;
                    two a;
                   a.x=i;
                   a.y=k;
                   myvector.push_back(a);
               }
           }
        }
    }

    sort(myvector.begin(), myvector.end());

    if(myvector.size()==0)
    {
        cout<<"NONE"<<endl;
    }
    else
    {
        for(int i = 0; i < myvector.size(); i++)
        {
            cout<<myvector[i].x<<' '<<myvector[i].y<<endl;
        }
    }
    return 0;
}
