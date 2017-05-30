#include <iostream>
using namespace std;

int main()
{
	int a;
	int sum = 0;
	while(a != -999)
	{
		cin>>a;

		if(a%2 == 0)
		{
			sum = sum + a;
		}
	}

	cout<<sum;
}

