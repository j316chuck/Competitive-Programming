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
    set<double> myset;

    myset.insert(2);
    myset.insert(2);
    myset.insert(3);
    myset.insert(4);
    myset.insert(5);

    set<double>:: iterator itr = myset.begin();

    for(;itr!=myset.end();itr++)
    {
        cout<<*itr<<'\n';
    }


}
