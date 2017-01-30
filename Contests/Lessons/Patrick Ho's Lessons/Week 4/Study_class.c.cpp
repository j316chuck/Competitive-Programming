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
using namespace std;

class Name
   {
    public:
    string person;
    int age[20];

    bool operator< (const myMan& a) const
    {return age >a.age;
    // make sort from old to young
    }
   };
int main()
{
    Name A[500];
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>A[i].person;
        cin>>A[i].age;
    }

    sort(A, A+N);

    for(int i = 0; i < N; i++)

    {
        cout<<A.age[i];
    }




}
