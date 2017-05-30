#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;

    for(int i = 0; i < s.size(); i++)
    {
        cout<<s[i];
    }
    cout<<'\n';

    string::iterator itr = s.begin();
    while(itr!= s.end())
    {
        cout<<(*itr);
        itr++;
    }
    cout<<'\n';

    string::iterator k = s.begin();
    while(k != s.end())
    {
        cout<<*k;
        k+=2;
    }
    cout<<'\n';
}
