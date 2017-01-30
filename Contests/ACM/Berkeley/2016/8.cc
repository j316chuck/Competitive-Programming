#include "contest.h"
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

vector<int> myarray;
int main(){
    //freopen("8.in", "r", stdin);
    int N;
    while(cin>>N){
        myarray.clear();
        for(int i = 0; i < N; i++){
            int a;
            cin>>a;
            myarray.push_back(a);
        }
        int total = 0;
        int shift = 0;
        for(int i = 0; i < N; i++){
            if(myarray[i] == i-shift+1){
                //cout<<"no shift: "<<myarray[i]<<" "<<i<<" "<<shift<<endl;
                continue;
            }else{
                total++;
                shift++;
                //cout<<"shift: "<<myarray[i]<<" "<<i<<" "<<shift<<endl;
            }
        }
        cout<<total<<endl;
    }

}

