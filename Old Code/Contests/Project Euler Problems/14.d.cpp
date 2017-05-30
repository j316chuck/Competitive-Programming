#include <iostream>
using namespace std;
int main()
{
	int hopp=0;
    __int64	n=1;

	for (int grans=1 ; grans<1000000 ; grans++)
	{
		n=grans;
		hopp=0;
		while (n>1)
		{
			if (n%2==0)
				n=n/2;
			else if (n%2!=0)
				n=((3*n)+1);
			hopp++;
		}
		if (hopp>510)
		{
			cout<<grans<<endl;
		}
	}
}

