#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    int x[100];
    int y[100];
    for(int i = 0; i < 2*N; i++)
    {
        cin>>x[i]>>y[i];

    }
    int ax;
    int bx;

    for(int i = 0; i < 100; i++ )
    {
        for(int j = -100; j < 100; j++)
        {
        int numA =0;
        int numB =0;
        for(int k = 0; k < 2*N; k++)
        {
            if(i*x[k]+(j)*y[k]<0)
            {
                numA++;
            }
            if(i*x[k]+j*y[k]>0)
            {
                numB++;
            }

        }
        if(numA==N && numB==N)
            {
                cout<<i<<' '<<j<<'\n';
            }

        }
    }
}
