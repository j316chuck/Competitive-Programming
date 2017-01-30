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

int main()
{
    map<string, int> chart;

    for(int i = 0; i < 5; i++)
    { string a;
        cin>>a;
        chart[a] = i;
    }

    map<string,int>::iterator itr = chart.begin();

    sort(chart.begin(),chart.end());

    for(int i = 0; i < chart.size(); i++)
    {
        cout<<(*itr).second<<' '<<(*itr).first;

        itr++;
    }
}
