#include <iostream>
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


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

using namespace std;

int main()
{
    char str[1000];

    cin>>str;
    int l = strlen(str);
    for(int i = strlen(str)-1; i >=0 ;i--)
    {
        cout<<str[i];
    }
}

/*
strlen(str)== char array length
strcmp(s1,s2) <-- Char array to compare
STL begin() end() length(), size();

review printf
