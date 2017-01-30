#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;

    std::vector<int> myArray;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin>>a;
        myArray.push_back(a);

    }
myArray.insert(myArray.begin()+5, 100);

    for(int i = 0; i < N+1; i++)
    {
      cout<<myArray[i]<<endl;

    }
}
