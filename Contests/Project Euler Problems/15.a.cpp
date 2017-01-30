#include <iostream>
using namespace std;

int main()
{
    long long gridsize = 10;
    long long a[gridsize+1][gridsize+1];

    for(int row = 0; row < gridsize+1; row++)
    {
       a[row][0] = 1;
    }

    for(int column = 0; column < gridsize+1; column++)
    {
       a[0][column] = 1;
    }

    for(int row = 1; row < gridsize+1 ; row++)
    {
        for(int column = 1; column < gridsize+1; column++)
        {
            a[row][column] = a[row-1][column]+ a[row][column-1];
            cout<<a[row][column]<<endl;
        }
    }


}
