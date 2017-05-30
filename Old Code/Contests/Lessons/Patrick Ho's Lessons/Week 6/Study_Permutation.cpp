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
    int N= 5;
    int a[5] = {1, 2, 3, 4, 5};
    int total = 0;
    do
    {
        total++;
       for(int i = 0; i < 5; i++)
       {
           cout<<a[i]<<' ';
       }
    cout<<'\n';
    }
    while(next_permutation(a, a+N));

    cout<<total<<'\n';
}
