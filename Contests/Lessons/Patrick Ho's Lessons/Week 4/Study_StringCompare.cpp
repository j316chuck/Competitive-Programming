#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    /*
    string a = "aadasd";
    string b= "aadasd";

    if(a==b)
    {
        cout<<"a";
    }
    else
        cout<<"asd";
        */
    char a[80]= "asdasd";
    char b[80]= "asdasd";

    if(strcmp(a,b)==0)
        cout<<"equal";
    else
        cout<<"not equal";

}
