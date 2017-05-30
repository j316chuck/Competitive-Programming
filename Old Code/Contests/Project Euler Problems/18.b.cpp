#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector< vector<int> >name;
    int sum = 0;

    for(int i = 0; i < 3; i++)
    {
        vector<int>tempname;
        for(int j = 0; j < i+1; j++)
        {
            int a;
            cin>>a;
            tempname.push_back(a);
        }
        name.push_back(tempname);
    }

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 1; j++){
            int counter = 0;
            sum = sum + name[i][counter];
            sum = sum + name[i][counter+1];

        }

    }




}
