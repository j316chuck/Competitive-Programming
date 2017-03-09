//#include "hello.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //hello();
    vector<int> A;
    for (int i = 0; i < 10; i++)
    {
        A.push_back(i);
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << ' ';
    }
    return 0;
}
