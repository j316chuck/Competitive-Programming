#include <iostream>
using namespace std;

#include<stdio.h>

int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common set bits of x and y
        int carry = x & y;

        // Sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

int main()
{
    printf("%d", Add(15, 32));
    return 0;
}
/*
    int i = 2;
	int i1 = 5;
	int i2 = i|i1;
	cout<<i2<<'\n';


	int i3 = 3<<2;

	cout<<i3<<'\n';

	int i4 = 64>>4;

	cout<<i4<<'\n';
*/
