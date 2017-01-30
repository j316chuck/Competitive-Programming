#include <iostream>
using namespace std;

int main()
{
     string str;
    getline(cin, str);

    for(int i = 0; i <str.length(); i++)
    {
        if(i%2 == 0)
            cout<<str[i];

    }
    for(int i = 0; i < str.length(); i++)
    {
        if(i%2 ==  1)
            cout<<str[i];

    }
}

