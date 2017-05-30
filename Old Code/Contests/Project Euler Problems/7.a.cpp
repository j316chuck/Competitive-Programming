#include <iostream>
using namespace std;

int Prime(int n)
{
    int counter = 0;

    for(int k = 2; k < n-1; k++){
        if(n%k == 0)
        {
            counter = counter+1;
        }
    }

     return counter;

}

int main()
{
    int counter1 = 0;
    int i;
    for(i = 2; i <1000000; i ++)
    {
        if(Prime(i)== 0){
            counter1=counter1++;
        }

        if(counter1==10001)
        {
            cout<<i<<endl;
            break;
        }

    }
}







