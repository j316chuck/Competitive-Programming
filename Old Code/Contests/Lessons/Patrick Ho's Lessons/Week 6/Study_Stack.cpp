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
    stack<string> myQ;
    myQ.push("Chuck");
    myQ.push("Andrew");
    myQ.push("Patrick");

    while(!myQ.empty())
    {
        string name = myQ.top();
        cout<<name<<'\n';

        myQ.pop();
    }

}
