#include <iostream>
using namespace std;

int main()
{

    float input[100];
    float value[100];
    int counter = 0;
for(int i = 0; i < 100; i++)
{
     cin>>input[i];

     if(input[i]== 0.00)
     {
         counter = i;
         break;
     }
}


for(int k= 0; k < counter; k++)
{
    cout<<input[k]<<endl;
}
}
