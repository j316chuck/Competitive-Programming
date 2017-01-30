#include <iostream>
using namespace std;
int paths = 0;
int Recursion(int i, int j)
{


    if(i==0 && j==0)
    {
        return 1;
    }
    else
    {
        if(i>0){
            paths = paths + Recursion(i-1,j );
        }
        if(j>0){
           paths = paths + Recursion(i, j-1);
        }

    }


}


int main()
    {
        int a= Recursion(3, 3);
        cout<<a<<endl;
    }
