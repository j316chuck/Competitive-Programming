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
using namespace std;
//using vector to solve the problem

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

struct Time
{
    int hour;
    int minute;
};
class CompareTime
{
    public:


       bool operator()(Time& T1, Time& T2)
       {
           if(T1.hour>T2.hour)
           {
               return true;
           }
           if(T1.hour =T2.hour&& T1.minute>T2.minute)
           {
               return true;
           }
           else
            return false;
       }
};
int main()
{
    priority_queue<vector<Time>,CompareTime> queue;
    queue.push(3, 2);
    queue.push(3, 45);
    queue.push(10, 15);

    while(!queue.empty())
    {
        cout<<queue.top()<<endl;
        pop
    }
}
