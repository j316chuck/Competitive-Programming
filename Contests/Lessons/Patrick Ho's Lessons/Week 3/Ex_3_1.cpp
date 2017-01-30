#include <cstdio>
using namespace std;

int main()
{
    char str[100];
    for(;;)
    scanf("%c",str);


    for(;;)
    {
        int i = 0;
        if(i%2 == 0)
        {
            printf("%c",str[i]);
        }
        i= i+2;
    }

    for(;;)
    {   int i = 1;
        if(i%2 == 1)
        {
            printf("%c",str[i]);
        }
        i = i +2;
    }



}
