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
/*

struct Time {
    int h; // >= 0
    int m; // 0-59
    int s; // 0-59
};
class CompareTime {
public:
    bool operator()(Time& t1, Time& t2)
    {
       if (t1.h < t2.h) return true;
       if (t1.h == t2.h && t1.m < t2.m) return true;
       if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
       return false;
    }
};

int main()
{
    priority_queue<Time, vector<Time>, CompareTime> pq;

    // Array of 4 time objects:

    Time t[4] = { {3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};

    for (int i = 0; i < 4; ++i)
       pq.push(t[i]);

    while (! pq.empty()) {
       Time t2 = pq.top();
       cout << setw(3) << t2.h << " " << setw(3) << t2.m << " " <<
       setw(3) << t2.s << endl;
       pq.pop();
    }

    return 0;
}

*/
class CompareTime
{
public:
  bool operator()(int& t1, int &t2 )
  {
      if (t1< t2)
        return true;
      else
        return false;
  }
};

int main()
{

    int t[6] = { 3, 2, 4, 5, 6, 7};
    priority_queue<int, vector<int>, CompareTime> pq;
    for(int i = 0; i < 6; i++)
    {
        pq.push(t[i]);
    }

    for(int i = 0; i < 6; i++)
    {
      int intae= pq.top();
      cout<<intae<<endl;
       pq.pop();
    }

}
