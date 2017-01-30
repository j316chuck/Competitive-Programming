#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int mem[10000];

int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (mem[n] != -1) return mem[n];
    return mem[n] = (fib(n-1)+fib(n-2));
}


int main(){
    memset(mem, -1, sizeof(mem));
    int n;
    scanf("%d", &n);
    fib(n);
    printf("%d", mem[n]);

}
