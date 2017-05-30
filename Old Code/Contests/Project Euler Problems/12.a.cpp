#include <iostream>
#include <cmath>
using namespace std;

long long Divisor(int a)
{
    int counter = 0;

    int square = sqrt(a);

    for(int k = 1;  k <= square ; k++){

        if(a%k==0){
            counter = counter + 2;
        }
    }
    if (square * square == a) {
        counter--;
    }
    cout<<counter<<endl;
    return counter;

}
int main()
{
    for(int b = 1; b < 10000000; b++)
    {
        if(Divisor(b*(b+1)/2)>= 500){

            cout<<b<<endl;
            cout<<b*(b+1)/2<<endl;

            break;
        }

    }
}
