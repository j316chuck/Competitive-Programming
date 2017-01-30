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

int getspace(string s)
{
    int counter = 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]==' ')
        {
            counter++;
        }
    }
    return counter;
}

string twosplit(string s)
{
    string one;
    string two;

    for(int i= 0; i < s.size(); i++)
    {
        if(s[i]==' ')
        {
            for(int k = 0; k < i; k++)
            {
                one[i]= s[i];
            }

            for(int k = i+1; k < s.size(); k++)
            {
                two[k-i-1]=s[k];
            }
        }

        cout<<two<<endl;
        cout<<one<<endl;
        return one;
        return two;
    }
}
int main()
{
    int a;
    cin>>a;
    string str;
  for(int i = 0; i < a+1; i++)
    {
        getline(cin, str);
        int count = getspace(str);

        if(count == 1)
        {
           str[0]=toupper(str[0]);

            for(int i =1; i < str.size();i++)
            {
                str[i]=tolower(str[i]);
            }
            cout<<str<<endl;
        }

        if(count == 2)
        {
           str[0]=toupper(str[0]);
            int check = 0;
            for(int i =1; i < str.size();i++)
            {
                str[i]=tolower(str[i]);

                if(str[i]==' ')
                {
                    check = i+1;
                    break;
                }
            }

            for(int i = check; i < str.size(); i++)
            {
                str[i]=toupper(str[i]);
            }
            cout<<str<<endl;
        }

         if(count == 3)
        {
           str[0]=toupper(str[0]);
            int check2 = 0;
            int check = 0;
            for(int i =1; i < str.size();i++)
            {
                str[i]=tolower(str[i]);

                if(str[i]==' ')
                {
                    check = i+1;
                    break;
                }
            }
            for(int i = check; i < str.size(); i++)
            {
                if(str[i]=='.')
                {
                    for(int k = check; k < i+1; k++)
                    {
                        str[k]=toupper(str[k]);
                    }
                }
                 else if(str[i]==' ')
                {
                    check2 = i+1;
                    break;
                }
                else
                {
                    str[i]= tolower(str[i]);
                }


            }

            for(int i = check2; i < str.size(); i++)
            {
                str[i]=toupper(str[i]);
            }
            cout<<str<<endl;
        }




    }
}
