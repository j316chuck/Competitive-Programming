#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

/*void increase(void* data, int psize){
    if(psize == sizeof(char))
        char* pchar; pchar = (char*) data; ++(*pchar);
    elseif(psize == sizeof(int))
        char* pchar; pchar = (int*) data; ++(*pchar);
}*/
int main(){
    /*int myvar = 25;
    int foo = &myvar;
    int bar = myvar;
    int baz = *foo;
    //& = address of operator
    //* is the dereference operator and can be read as value pointed to by
    cout<< myvar == 25 <<endl;
    cout<< &myvar <<endl;
    cout<< foo == 1776 <<endl;
    cout<<*foo == 25<<endl;*/

    /*int *number; //pointer;
    char *character;
    double *decimal;*/
    /*int firstvalue, secondvalue;
    int * mypointer;
    mypointer = &firstvalue;
    *mypointer = 10;
    mypointer = &secondvalue;
    *mypointer = 20;
    cout<<firstvalue<<' '<<secondvalue<<endl;*/


    /*int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;
    p1 = &firstvalue;
    p2 = &secondvalue;
    *p1 = 10;
    *p2 = *p1;
    p1 = p2;
    *p1 = 20;
    cout<<firstvalue<<' '<<secondvalue<<endl;*/

    //arrays
    /*int numbers[5];
    int * p;
    p = numbers; *p = 10;
    p++; *p = 20;
    p = &numbers[2]; *p =30;
    p = numbers + 3; *p = 40;
    p = numbers; *(p+4) = 50;
    for(int i = 0; i < 5; i++)
        cout<<*(p+i)<<endl;
    */

    /*int myvar;
    int *myptr = &myvar;
    myvar = 10;
    cout<<*myptr<<endl;*/

    /*int x;
    int y = 10;
    const int * p = &y;
    x = *p;
    //*p = x;
    //cout<<*p<<endl;
    //strings
    const char * foo = "hello";
    cout<<foo[4]<<endl;
    cout<<*(foo+4)<<endl;*/

    //pointers to pointers
    /*char a;
    char *b;
    char **c;
    a = 'z';
    b = &a;
    c = &b;
    cout<<*c<<**c<<*b<<a<<endl;*/

    //pointers as void
    /*char a = 'x';
    int b = 1602;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    cout<<a<<b<<'\n';
    return 0;*/

    //null pointer
    /*int *p = 0;
//    int *q = nullptr;
    if(p == NULL)
        cout<<"NULL"<<endl;*/

    //pointers to function
    int (*minus)(int, int) = subtraction;
    m = operation(7, 5, minus);

}
