#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int a[100];
    for(int i= 0; i < s.size(); i++)
    {
        a[i]= s[i]-'o'+61;
    }
    for(int i= 0; i < s.size(); i++)
    {
        cout<<a[i]<<endl;
    }
}
