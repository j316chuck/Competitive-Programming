#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
  char str[] = "almost every programmer should know memset!";
  memset (str,'+',10);
  puts(str);
  return 0;

}









/*char * strncpy ( char * destination, const char * source, size_t num );
Copy characters from string
Copies the first num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.

No null-character is implicitly appended at the end of destination if source is longer than num. Thus, in this case, destination shall not be considered a null terminated C string (reading it as such would overflow).
*/
/*
int main ()
{
  char str1[]= "To be or not to be";
  char str2[40];
  char str3[40];

  /* copy to sized buffer (overflow safe): */
 // strncpy ( str2, str1, sizeof(str2) );

  /* partial copy (only 5 chars): */
  /*
  strncpy ( str3, str2, 5 );
  str3[5] = '\0';   /* null character manually added */
/*
  puts (str1);
  puts (str2);
  puts (str3);

  return 0;
}
*/
