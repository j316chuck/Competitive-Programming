#include <iostream>
using namespace std;


bool isSingleDigit (int x)
{
  if (x >= 0 && x < 10) {
    return true;
  } else {
    return false;
  }
}

int main()
{
    int a;
    cin>>a;
    cout<<isSingleDigit(a);
}
