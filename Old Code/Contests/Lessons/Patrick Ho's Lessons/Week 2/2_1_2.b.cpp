#include <cstdio>
using namespace std;

int main()
{
    char cIn;
    int sum = 0;
    int snumber = 0;
    for(int i = 0; i < 100; i++)
    {
        scanf("%c", &cIn);
        if(cIn=='\n')
            break;
        else if(cIn==' ')
        {
            sum++;
        }
        else if(cIn=='s')
        {
            snumber++;
        }
    }

    printf("'s':%d\n",sum);
     printf("SPACE:%d\n",snumber);
}
