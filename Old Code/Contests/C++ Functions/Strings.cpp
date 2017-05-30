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
    //converting string to int
    string myString ="45";
    int value =atoi(myString.c_str());
    cout<<value<<endl;
    cout<<value+10<<endl;

    //method 2
    int value2=myString[0]-'0';
    cout<<value2+10<<endl;

    //converting int to string

    int a=19;
    stringstream ss;
    ss<<a;
    string str=ss.str();
    cout<<str+"0"<<endl;

    //checking if string are equal
    string k= "abc";
    string l="abc";
    if(k==l)
        cout<<"abc"<<endl;

    string asd="as\k";
    for(int i=0; i<asd.length(); i++){
        if(asd[i]=='\\')
            cout<<"alksdjsk"<<endl;
    }
    //double to int and vice versa
    double x = 10.3;
    int y;
    y = int (x);    // functional notation
    y = (int) x;    // c-like cast notation
    cout<<x<<y<<endl;
    x= double (y);
    cout<<x<<endl;

    //checking about substrings
    /*string string1="We think in generalities";
    string string2=string1.substr(5,3);
    size_t pos =str.find("live");
    string string3=str.substr(pos);
    cout<<string2<<' '<<string3<<endl;*/


}
