#include <cstdio>
int main ()
{
char str[80];
int i;
printf("Enter your family name: ");
//cout<<"Enter your family name: ";
fflush(stdout);//flush the output buffer
scanf("%s",str);
printf("Enter your age: ");
fflush(stdout);
scanf("%d",&i);
printf("Mr. %s, %d years old.\n",str, i);
printf("Mr. %s, %d years old.\n", str, i);
printf("Enter a hexadecimal number: ");
fflush(stdout);
scanf("%x",&i);
printf("You have entered %#x(%d).\n",i,i);
printf("Your number is %x,%d\n", i, i);
return 0;

}
