
/*
USER: jack.ne1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#define MOD 9901
#define CODE_WORKS true
using namespace std;


int main(){
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    int grid[201][101];
    memset(grid, 0, sizeof(grid));
    grid[1][1] = 1;
    grid[3][2] = 1;
    grid[5][3] = 2;
    grid[7][3] = 1;
    grid[7][4] = 4;

    for(int i = 3; i < 7; i++){
        int id = pow(2, i) - 1;
        grid[id][i] = 1;
    }
    for(int n = 9; n < 201; n += 2){
        for(int k = 1; k < 101; k++){
            if(grid[n][k] != 0) continue;
            int m = n - 2;
            while(m > 0){
                int comp = grid[m][k - 1], partial = 0;
                if(comp == 0){
                    m -= 2;
                    continue;
                }
                for(int i = 1; i < k - 1; i++){
                    partial += grid[n - 1 - m][i];
                }
                grid[n][k] += comp * (partial % MOD) * 2;
                grid[n][k] += comp * grid[n - 1 - m][k - 1];
                grid[n][k] %= MOD;
                m -= 2;
            }
            grid[n][k] %= MOD;
        }
    }
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 201; j++){
            if(grid[j][i]!=0){
                cout<<j<<' '<<i<<' '<<grid[j][i]<<endl;
            }
        }
    }
    int N, K;
    cin >> N >> K;
    cout << grid[N][K] << endl;
}
