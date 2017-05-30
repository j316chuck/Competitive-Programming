/*
ID: j316chuck
PROG: pprime
LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

vector<int> palindrome;
int table[100001];
int counter;
bool check(int a){
    for(int i=3; i <=sqrt(a); i++){
        if(a%i==0)
            return false;
    }
    return true;
}



int main()
{
    Rd("pprime.in");
    Wt("pprime.out");
    int a,b;
    cin>>a>>b;
    //palindrome[1]=true;
    //cout<<palindrome[0]<<palindrome[1]<<endl;
    //int counter=0;

    for(int i=5; i<10; i+=2){
            if(check(i)){
             table[counter]=i;
                counter++;
            }
    }
    for(int i=1; i<10; i+=2){
            int num=i*10+i;
            if(check(num)){
                table[counter]=num;
                counter++;
            }
    }
    for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            int num=i*100+i+j*10;
            if(check(num)){
                table[counter]=num;
                counter++;
            }
        }
    }
     for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            int num=i*1000+i+j*100+j*10;
            if(check(num)){
                table[counter]=num;
                counter++;
            }

        }
    }
     for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
               int num=i*10000+i+j*1000+j*10+k*100;
                if(check(num)){
                table[counter]=num;
                counter++;
            }
            }
        }
    }
    for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                int num=i*100000+i+j*10000+j*10+k*1000+k*100;
               if(check(num)){
                table[counter]=num;
                counter++;
            }
            }
        }
    }
    for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                for(int l=0; l<10; l++){
                        int num=i*1000000+i+j*100000+j*10+k*10000+k*100+l*1000;
                        if(check(num)){
                        table[counter]=num;
                        counter++;
                    }

                }
            }
        }
    }
    for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                for(int l=0; l<10; l++){
                        int num=i*10000000+i+j*1000000+j*10+k*100000+k*100+l*10000+l*1000;
                        if(check(num)){
                        table[counter]=num;
                        counter++;
                    }

                }
            }
        }
    }
     for(int i=1; i<10; i+=2){
         for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                for(int l=0; l<10; l++){
                    for(int m=0; m<10; m++){
                        int num=i*100000000+i+j*10000000+j*10+k*1000000+k*100+l*100000+l*1000+m*10000;
                       if(check(num)){
                        table[counter]=num;
                        counter++;
                    }
                    }
                }
            }
        }
    }

for(int i=0; i <counter; i++){
            cout<<table[i]<<",  ";

    }
}
