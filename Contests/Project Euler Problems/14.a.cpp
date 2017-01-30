#include <iostream>
using namespace std;

int main()
{

long long sequenceLength = 0;
long long sequence = 1000000;
long long startingNumber = 0;

for(int i = 1000000; i > 0; i--)
{
long long length = 1;

    while(sequence !=1)
    {
        if(sequence %2 == 0)
        {
            sequence = sequence / 2;
        }

        else
        {
            sequence = (sequence * 3) + 1;
        }
        length = length + 1;
    }


sequence = i;

    if (length > sequenceLength) {
        sequenceLength = length;
        startingNumber = i;
        cout<<length<<endl;
        cout<<i+1<<endl;

    }


    }
}
