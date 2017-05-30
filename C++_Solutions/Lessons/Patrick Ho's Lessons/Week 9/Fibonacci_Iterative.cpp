#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int mem[10000];
    memset(mem, -1, sizeof(mem));
    mem[0] = 0;
    mem[1] = 1;

    for(int i = 2; i <= n; i++){
        mem[i] = mem[i-1] + mem[i-2];
    }
    printf("%d", mem[n]);


}


