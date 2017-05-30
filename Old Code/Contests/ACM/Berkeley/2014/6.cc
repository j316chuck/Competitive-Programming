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

long long summation(long long N){
    return N*(N+1)/2;
}
long long binarysearch(long long N, long long top, long long bottom){
    long long middle = (top+bottom)/2;
    //cout<<middle<<' '<<top<<' '<<bottom<<' '<<N<<summation(middle)<<endl;
    if(summation(top) == N){
        return top;
    }else if(summation(bottom) == N){
        return bottom;
    }else if(top-bottom == 1 && summation(top) > N && summation(bottom) < N){
        return top;
    }else if(summation(middle) > N){
        top = middle;
        return binarysearch(N, top, bottom);
    }else if(summation(middle) < N){
        bottom = middle;
        return binarysearch(N, top, bottom);
    }else if(summation(middle) == N)
        return middle;
}
int main(){

    freopen("6.in", "r", stdin);
    long long N;
    while(cin>>N){
        long long res = binarysearch(N, pow(10, 7), 1);
        //cout<<res<<' '<<summation(res)<<' '<<num<<endl;
        long long num = summation(res)- N + 1;
        long long den = res-num+1;
        printf("%lld => %lld/%lld \n", N, num, den);
    }
    exit(0);
}
