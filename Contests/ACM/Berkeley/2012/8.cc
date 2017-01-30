//#include "contest.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

string binary(int N){

    string s;
    while(N!=0){
        if(N%2==1)
            s+="1";
        else
            s+="0";
        N=N/2;
    }
    return s;
}

long long perm[66][12];

int main(){

    freopen("8.in", "r", stdin);

    for(int i = 0; i < 66; i++){
        perm[i][0] = 1;
    }for(int i = 1; i < 12; i++){
        perm[0][i] = 0;
    }
    for(int i = 1; i <= 65; i++){
        for(int k = 1; k <= i && k < 12; k++){
            perm[i][k] = (perm[i-1][k-1] + perm[i-1][k]);
        }
    }
    //cout<<perm[10][3]<<endl;
    long long N;
    while(cin>>N){
        string s = binary(N);
        reverse(s.begin(), s.end());
        int one = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                one++;
            }
        }
        int realone = one;
        int length = s.size();
        int zero = length-one;
        long long total = 0;
        if(length-2 >=0){
            for(int i = length-2; i >= one-1; i--){
                total+=perm[i][one-1];
            }
        }

        one--;

        for(int i = 1; i < length; i++){
            if(s[i] =='0')
                continue;
            else if(s[i] =='1'){
                if(one >= 1 && length-i-1 >= one){
                    total+=perm[length-i-1][one];
                    //cout<<total<<endl;
                    //cout<<i<<' '<<one<<endl;
                }
                one--;
            }
        }
        printf("%lld is number %lld in the sequence of numbers with %d 1-bits.\n", N, total, realone);
        //cout<<total<<endl;
        //cout<<s<<' '<<one<<endl;
        //cout<<mem[3][3]<<endl;
        //cout<<mem[25][10]<<endl;
    }
    exit(0);
}
