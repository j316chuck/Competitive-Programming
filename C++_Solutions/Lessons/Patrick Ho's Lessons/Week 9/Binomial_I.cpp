#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int mem[100][100];
    int n, k;
    scanf("%d %d", &n, &k);
    //memset(mem, 0, sizeof(mem));
    for(int i = 0; i < n; i++){
        mem[i][0] = 1;
    }
    for(int i = 1; i < k; i++){
        mem[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            mem[i][j] = mem[i-1][j-1] + mem[i-1][j];
        }
    }
    printf("%d", mem[n][k]);
}
