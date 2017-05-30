#include <iostream>
using namespace std;

int main()
{
    int matrix[10][10];

    for(int i = 0; i < 10; i++){
        matrix[i][0]= i;
        matrix[0][i]= i;
    }

    for(int i = 1; i < 10; i++){
        for(int r = 1; r < 10; r++){
            matrix[i][r]= matrix[i][0]*matrix[0][r];
        }
    }

    for(int i = 0; i < 10; i++){
        for(int r = 0; r < 10; r++){
            cout<<matrix[i][r]<<" ";
        }
        cout<<""<<endl;
    }

}
