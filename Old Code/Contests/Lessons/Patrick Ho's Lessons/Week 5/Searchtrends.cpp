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

class my_vote
{
    public:
    string searchterms;
    int counter;

    bool operator < (const my_vote &a) const
    {
        return counter>a.counter;
    }
};
int main()
{
    map<string,int> myMap;

    string name;

      int a;
      cin>>a;
      for(int i = 0; i < a; i++)
      {
          cin>>name;
            map<string,int>::iterator itr = myMap.find(name);
            if(itr!=myMap.end())
            {
                (*itr).second=(*itr).second+1;
            }
            else
            {
                myMap[name]=1;
            }
      }

      vector <my_vote> readout;
        map <string, int>::iterator iter = myMap.begin();
       for(; iter != myMap.end(); iter++)
       {
          my_vote a;
          a.counter = (*iter).second;
          a.searchterms = (*iter).first;
            readout.push_back(a);
       }
        sort(readout.begin(), readout.end());


        if(a>10)
        {
              for(int i =0; i < 10; i++)
                {
                    cout<<readout[i].counter<<' '<<readout[i].searchterms<<endl;
                }
        }

        else
        {
              for(int i =0; i < a; i++)
                {
                    cout<<readout[i].counter<<' '<<readout[i].searchterms<<endl;
                }
        }

}
