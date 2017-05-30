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

vector<long long> myarray;
vector<long long> prefixsum;
long long N, P;
int main(){

    freopen("6.in", "r", stdin);

    while(cin>>N>>P){
        myarray.clear();
        myarray.push_back(0);
        prefixsum.push_back(0);
        long long sum =0;
        for(int i = 0; i < N; i++){
            long long a; cin>>a;
            myarray.push_back(a);
            sum+=a;
            sum = sum % P;
            prefixsum.push_back(sum);
        }

        int Q;
        cin>>Q;
        for(int j = 0; j < Q; j++){
            int a;
            cin>>a;
            if(a == 1){
                int t, g, c;
                cin>>t>>g>>c;
                long long counter = c;
                for(int i = t; i <= g; i++){
                    prefixsum[i]= ((prefixsum[i]-prefixsum[t-1])%P)*c;
                    prefixsum[i]= prefixsum[i]%P;
                    prefixsum[i]+=prefixsum[t-1];
                    prefixsum[i]= prefixsum[i]%P;
                }
            }else if(a == 2){
                int t, g, c;
                cin>>t>>g>>c;
                long long counter = c;
                for(int i = t; i <= g; i++){
                    prefixsum[i]+=counter;
                    prefixsum[i]=prefixsum[i]%P;
                    counter+=c;
                    counter = counter%P;
                }
            }else if(a == 3){
                int t, g;
                cin>>t>>g;
                cout<<prefixsum[g]-prefixsum[t-1]<<endl;
            }
        }
    }
}
