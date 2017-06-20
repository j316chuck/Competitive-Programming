//from http://en.cppreference.com/w/cpp/preprocessor/replace

#include <iostream>
using namespace std;

//make function factory and use it
#define FUNCTION(name, a) int fun_##name() { return a;}
#define BOOL //BOOL does not have to be defined to anything...

FUNCTION(abcd, 12)
FUNCTION(fff, 2)
FUNCTION(qqq, 23)

#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) std::cout << #a << '\n'
#ifdef BOOL
int a[10];
#endif // BOOL


int main()
{
    std::cout << "abcd: " << fun_abcd() << '\n';
    std::cout << "fff: " << fun_fff() << '\n';
    std::cout << "qqq: " << fun_qqq() << '\n';
    std::cout << FUNCTION << '\n';
    OUTPUT(million);               //note the lack of quotes
    cout << a[0] << endl;
}
