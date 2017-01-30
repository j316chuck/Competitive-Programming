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
int maximum = 0;
int counter =0;
vector< vector<char> > arr;
void floodfill(int i, int j)
{
    if(i<0||j < 0 || j>= N|| i >= N)
    {
        return;
    }
    if(arr[i][j]!='*')
    {
        return;
    }

    arr[i][j]='x';
    counter++;

     floodfill(i-1, j);
    floodfill(i+1, j);
    floodfill(i, j-1);
    floodfill(i, j+1);

}

int main()
{
    cin>>N;
    Rd("Floodfill5.in");
    //Wt("Floodfill5.out");
    for(int i = 0; i < N; i++)
    {
        vector<char> random;
        for(int j = 0; j < N; j++)
        {
            char a;
            cin>>a;
            random.push_back(a);
        }
        arr.push_back(random);
    }


    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j]=='*')
            {
                counter = 0;
                floodfill(i, j);
                 if(counter> maximum)

                    {
                        maximum = counter;
                    }
            }
        }
    }

    cout<<maximum<<endl;
}
