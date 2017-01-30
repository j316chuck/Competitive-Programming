#include <iostream>
using namespace std;

int main()
{
    int a[12];
    a[1]= 1;
    a[2] = 32;
    a[3] = 60;
    a[4] = 91;
    a[5] = 121;
    a[6] = 152;
    a[7] = 182;
    a[8] = 213;
    a[9] = 244;
    a[10] = 274;
    a[11] = 305;
    a[12] = 335;
    int counter = 0;

    for(int i = 1; i < 101; i++)
    {
    if(i%4 != 0)
       {

        for(int k = 1; k <= 12; k++)
        {
            a[k]= a[k]+ 365*1;

            if(a[k]%7 == 0);
            {
                counter = counter+1;
            }
        }
       }

    else if(i%4 == 0)
        {
            for(int k = 1; k <= 12; k++)
            {

            a[k]= a[k]+365*1 +1;

            if(a[k]%7 == 0);
                {
                counter = counter+1;
                }
            }
        }

    }
     cout<<counter;

}
