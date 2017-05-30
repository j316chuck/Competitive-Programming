#include <iostream>
using namespace std;
/*
int recursion(int a)
{
    if(a==0)
    {
        return 1;
    }
    else
    {
        return (a*recursion(a-1));
    }

}
int main()
{
    int i;
    cin>>i;
    cout<<recursion(i)<<'\n';
}
*/
int step(int a)
{
    if(a==1)
    {
        return 1;
    }

    else if(a==2)
    {

        return 2;
    }

    else
    {
        return (step(a-1)+step(a-2));
    }
}

int main()
{
    cout<<step(20);
}
