/*
ID: j316chuck
PROG: milk3
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

int A, B, C;
int amountA,amountB, amountC;
bool possible[21];
int counter =0;

class three
{
    public:
    int first,second, third;
};

three paths[10000];

bool checkcycle()
{
    for(int i =0; i < counter; i++)
    {
        if(paths[i].first==amountA&&paths[i].second==amountB&&paths[i].third==amountC)
            return false;
    }
    return true;
}
void Recursion()
{
    if(amountA==0)
    possible[amountC]==true;
        return;
    paths[counter].first=amountA;
    paths[counter].second=amountB;
    paths[counter].third=amountC;

    if(checkcycle()==false)
        return;
    if(B<amountA+amountB){
        amountB=B;
        amountA=amountA+amountB-B;
        Recursion();
    }if(B>=amountA+amountB){
        amountB=amountA+amountB;
        amountA=0;
        Recursion();
    }if(C<amountC+amountA){
        amountC=C;
        amountA=amountA+amountC-C;
        Recursion();
    }if(C>=amountC+amountA){
        amountC=amountC+amountA;
        amountA=0;
        Recursion();
    }if(A<amountB+amountA){
        amountA=A;
        amountB=amountB+amountA-A;
        Recursion();
    }if(A>=amountA+amountB){
        amountA=amountA+amountB;
        amountB=0;
        Recursion();
    }if(C<amountB+amountC){
        amountC=C;
        amountB=amountB+amountC-C;
        Recursion();
    }if(C>=amountB+amountC){
        amountC=amountB+amountC;
        amountB=0;
        Recursion();
    }if(A<amountA+amountC){
        amountA=A;
        amountC=amountC+amountA-A;
        Recursion();
    }if(A>=amountA+amountC){
        amountA=amountA+amountC;
        amountC=0;
        Recursion();
    }if(B<amountB+amountC){
        amountC=C;
        amountB=amountB+amountC-C;
        Recursion();
    }if(B>=amountB+amountC){
        amountB=amountB+amountC;
        amountC=0;
        Recursion();
    }
     counter++;
}

int main()
{
    Rd("milk3.in");
    //Wt("milk3.out");

    cin>>A>>B>>C;
    amountA=0;
    amountB=0;
    amountC=C;
    Recursion();
    for(int i = 0; i < C; i++)
    {
        if(possible[i]==true)
        {
            cout<<i<<endl;
        }
    }
}
