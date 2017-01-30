/*
ID: peiqistar1
PROG:
LANG: C++
 */
#include <cstdio>

int main ()
{
	//  print 1st line
	for (int i=0; i<10; i++)
	{
		if (i==0)
			printf("%4c|", ' ');
		else
			printf("%4d", i);
	}
	printf("\n");

	//print 2nd line
	for (int i=0; i<10; i++)
	{
		if (i==0)
			printf("%4c|", '-');
		else
			printf("%4c", '-');
	}
	printf("\n");

	//print matrix
	for (int r=0; r<9; r++)
	{
		for (int i=0; i<10; i++)
		{
			if (i==0)
				printf("%4d|", r+1);
			else
				printf("%4d", (r+1)*i);
		}
		printf("\n");
	}

	return 0;
}



