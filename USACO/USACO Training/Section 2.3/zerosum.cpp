/*ID: j316chuck
PROG: zerosum
LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int N;
int result;

void Recurse(int curr, int total, int carry, int arr[]){
    //cout<<curr<<' '<<total<<' '<<carry<<endl;
    if(curr == N && total == 0){
        result+=1;
        cout<<1;
        for(int i = 2; i <= 10; i++){
            if(arr[i] == -1)
                break;
            else if(arr[i] == 0)
                cout<<' '<<i;
            else if(arr[i] == 1)
                cout<<'+'<<i;
            else if(arr[i])
                cout<<'-'<<i;
        }cout<<endl;
        //cout<<result<<endl;
        return;
    }
    if(curr == N)
        return;

    arr[curr+1] = 0; //*
    if(carry < 0){
        Recurse(curr+1, total+=9*carry-curr-1, 10*carry-(curr+1), arr);
        total-=(9*carry-curr-1);
    }else{
        Recurse(curr+1, total+=9*carry+curr+1, 10*carry+(curr+1), arr);
        total-=(9*carry+curr+1);
    }

    arr[curr+1] = 1; //+
    Recurse(curr+1, total+=curr+1, curr+1, arr);
    total-=(curr+1);

    arr[curr+1] = 2; //-
    Recurse(curr+1, total-=(curr+1), -(curr+1), arr);
    total+=(curr+1);

    arr[curr+1] = -1;
}

int main(){
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    cin>>N;
    int arr[11];
    memset(arr, -1, sizeof(arr));
    //cout<<N<<endl;
    Recurse(1, 1, 1, arr);
}
