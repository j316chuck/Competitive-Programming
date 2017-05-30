#include <iostream>
#include <vector>
using namespace std;
int N;

void floodfill(vector<vector<char> > &arr, int i, int j) {
        if (arr[i][j] != '*') return;
        arr[i][j] = 'x';
        floodfill(arr, i + 1, j);
        floodfill(arr, i - 1, j);
        floodfill(arr, i, j + 1);
        floodfill(arr, i, j - 1);
}

vector<vector<char> > arr;
//input
int counter = 0;
int main()
{
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
for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i][j] == '*') {
                        floodfill(arr, i, j);
                        counter++;
                }
        }
}
cout << counter << "\n";
}
