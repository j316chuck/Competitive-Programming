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


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

/*
class person{
public:
    string name;
    int age;

    bool operator<(const name&a)const
    {
        return age < a.age;
    }
};
int main (int argc, char ** argv)
{
    int N;
    cin>>N;

    person A[5000];
    for(int i = 0; i < N; i++
    {
        cin>>A[i].name>>' '>>A[i].age;
    }

   sort(A, A+N);

   for(int i = 0; i < N; i++)
   {

       cout<<A[i].name;

       if(i!=N-1)
       {
           cout<<" ";
       }

   }

   cout<<'\n';
}
*/

class person{
public:
    string name;
    int age;
};
int main (int argc, char ** argv)
{
    int N;
    cin>>N;

    person A[5000];
    for(int i = 0; i < N; i++)
    {
        cin>>A[i].name>>' '>>A[i].age;
    }

   sort(A, A+N);

   for(int i = 0; i < N; i++)
   {

       cout<<A[i].name;

       if(i!=N-1)
       {
           cout<<" ";
       }

   }

   cout<<'\n';
}
