#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int mem[1000][1000];

int bin(int n, int k){
    if (k == 0) return 1;
    if (n == 0) return 0;
    if(mem[n][k] != -1) return mem[n][k];

    return mem[n][k] = bin(n-1, k-1) + bin(n-1, k);
}

int main(){
    memset(mem, -1, sizeof(mem));
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d",bin(n, k));

}
