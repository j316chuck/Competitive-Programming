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

class box
{
public:
    string name;
    int age;
     bool operator < (const box &a) const
    {
        return age>a.age;
    }
};
int main()

{
    int length;
    vector<box> myarray;
    cin>>length;

    for(int i = 0; i < length; i++)
    {
        string str;
        int random;
        cin>>str>>random;

        box a;
        a.name = str;
        a.age = random;

        myarray.push_back(a);
    }

    sort(myarray.begin(), myarray.end());



    vector<box>::iterator itr;
    for(itr = myarray.begin(); itr != myarray.end(); itr++)
    {
        cout<<(*itr).age<<endl;
    }



}

