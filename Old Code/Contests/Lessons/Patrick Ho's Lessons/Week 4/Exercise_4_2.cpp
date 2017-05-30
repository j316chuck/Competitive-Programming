#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int a[3];
    char arr[5];
    int arra[5];
    int substitute[5];
    int multiply =1;
    int total[2];
    total[0] = 0;
    total[1] = 0;

    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k < 5; k++)
        {
            cin>>arr[k];
        }

         for(int k = 0; k < 5; k = k+2 )
        {

            arra[k] = arr[k]-'0';
            substitute[k] = arr[k]-'0';

        }

        for(int k = 1; k < 5; k=k+2)
        {
            if(k==1)
            {
                if(arr[k]=='-')
                {
                arra[k+1]=arra[k-1]-arra[k+1];
                }

                else if(arr[k]=='+')
                {
                arra[k+1]=arra[k-1]+arra[k+1];
                }

                else if(arr[k]=='*')
                {
                arra[k+1]=arra[k-1]*arra[k+1];
                }
            }
            else if(k==3)
            {
                if(arr[k]=='-')
                {
                arra[k+1]=arra[k-1]-arra[k+1];
                }

                else if(arr[k]=='+')
                {
                arra[k+1]=arra[k-1]+arra[k+1];
                }

                else if(arr[k]=='*')
                {
                arra[k+1]=arra[k-1]*arra[k+1];
                }
            }
        }

        total[0]=arra[4];


        for(int k = 3; k > 0; k=k-2)
        {
            if(k==3)
            {
                if(arr[k]=='-')
                {
                substitute[k-1]=substitute[k-1]-substitute[k+1];
                }

                else if(arr[k]=='+')
                {
                substitute[k-1]=substitute[k-1]+substitute[k+1];
                }

                else if(arr[k]=='*')
                {
                substitute[k-1]=substitute[k-1]*substitute[k+1];
                }
            }
            else if(k==1)
            {
                if(arr[k]=='-')
                {
                substitute[k-1]=substitute[k-1]-substitute[k+1];
                }

                else if(arr[k]=='+')
                {
                substitute[k-1]=substitute[k-1]+substitute[k+1];
                }

                else if(arr[k]=='*')
                {
                substitute[k-1]=substitute[k-1]*substitute[k+1];
                }
            }
        }
        total[1]=substitute[0];


        if(total[1]>total[0])
        {
            cout<<total[1]<<'\n';
        }
        else
        {
        cout<<total[0]<<'\n';
        }
    }
}
