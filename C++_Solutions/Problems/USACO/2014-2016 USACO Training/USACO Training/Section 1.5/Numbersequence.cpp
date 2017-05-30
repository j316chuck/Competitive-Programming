#include <iostream>
#include <algorithm>
using namespace std;
int memo[n+1];
int getMinsteps(int n)
{
    if(n==1) return 0;
    if(memo[n]!= -1) return memo[n];
    int r= 1+getMinsteps(n-1);
    if(n%2==0) r = min(r, 1+getMinsteps(n/2));
    if(n%3==0) r = min(r, 1+getMinsteps(n/3));
    memo[n]=r;

    return r;
}
int main()
{
    cin>>N;
}
