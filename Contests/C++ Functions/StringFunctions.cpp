#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   string str("This is an example sentence.");
   cout<<str<<endl;
   str.erase(10,8);
   cout<<str<<endl;

   str.insert(8,"great ");
   cout<<str<<endl;

   string stri="good";
   stri.insert(3,"i");
   cout<<stri<<endl;
   stri.erase(3,1);
   cout<<stri<<endl;
   stri.insert(3,"i");
   cout<<stri<<endl;

    char a='a';
    stringstream ss;
    ss>>a;
    cout<<a<<endl;

    string s = "abcdef";
    swap(s[1], s[4]);
    cout<<s<<endl;

}
