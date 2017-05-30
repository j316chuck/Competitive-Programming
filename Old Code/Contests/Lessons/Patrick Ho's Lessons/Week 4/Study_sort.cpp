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
bool mycomp(const double &a, const double &b)
{
    if(a>b) return true;
    else return false;
}

int main()
{
    double a[5] = {1.2, 5.3, 2.4, 5.5, 7.8};
    sort(a,a+5);

    for(int i = 0; i < 5; i++)
    {
        cout<<a[i]<<'\n';
    }

    sort(a, a+5, mycomp);
    for(int i = 0; i < 5; i++)
    {
        cout<<a[i]<<'\n';
    }
}
