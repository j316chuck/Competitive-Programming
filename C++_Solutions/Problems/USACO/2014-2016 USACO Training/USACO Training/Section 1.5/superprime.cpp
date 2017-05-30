/*
ID: j316chuck
PROG: sprime
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
int N;


int main()
{
    cin>>N;

    for
}
/*bool isprime(int a)
{
    if(a==2) return true;
    if(a==1) return false;
    if (a % 2 == 0) return false;
    for(int i=3; i <sqrt(a) + 1; i+=2)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main()
{
    Rd("sprime.in");
    Wt("sprime.out");
    cin>>N;


    for(int i=pow(10,N-1) ; i<pow(10,N) ; i++)
    {
        bool allprime = true;
        int icopy = i;
        for(int k=0; k < N; k++)
        {

            if(!isprime(icopy))
            {
                allprime = false;
                break;
            }
            icopy /= 10;

        }
        if (allprime)
        cout << i << "\n";
    }

}
