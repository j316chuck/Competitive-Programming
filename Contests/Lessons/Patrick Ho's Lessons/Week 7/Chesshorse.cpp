/*
ID:
PROG:
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
#include <iostream>
using namespace std;

int a, b;
int Recursion(int x, int y)
{


   if(x == 0 || y == 0){
       return 1;
   }else if(x==a+2 && y== b+1){
       return 0;
   }else if(x==a+2 && y== b-1){
       return 0;
   } else if(x==a+1 && y== b-2){
       return 0;
   } else if(x==a+1 && y== b+2){
       return 0;
   } else if(x==a-1 && y== b+2){
       return 0;
   } else if(x==a-1 && y== b-2){
       return 0;
   } else if(x==a-2 && y== b+1){
       return 0;
   } else if(x==a-2 && y== b-1){
       return 0;
   } else if(x==a&& y==b){
   return 0;}


    else {
        return Recursion(x-1, y) + Recursion(x, y-1);
    }

}

int main()
{
    int x, y;
   cin>>x>>y>>a>>b;

   cout<<Recursion(x,y)<<endl;

}
