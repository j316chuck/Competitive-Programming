#include <iostream>
#include <vector>
using namespace std;
vector< vector<char> > arr;
int maximum =-1;
int counter = 0;
void floodfill(int i, int j, int count)
{
    if(arr[i][j]!='*')
        return;
    arr[i][j]=='x';
    count++;
     if(maximum < count){
        maximum=count;
    }
    floodfill(i+1, j, count);
    floodfill(i-1, j, count);
    floodfill(i, j+1, count);
    floodfill(i, j-1, count);



}
int main()
{
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        vector<char> b;
        for(int j = 0; j < N; j++)
        {
            char a;
            cin>>a;
            b.push_back(a);
        }
        arr.push_back(b);
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0;  j < N; j++)
        {
            if(arr[i][j]=='*')

                floodfill(i, j, 0);
        }
    }
    cout<<maximum<<endl;
}
