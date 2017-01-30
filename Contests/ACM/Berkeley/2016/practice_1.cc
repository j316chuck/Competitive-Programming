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


int main(){
    //freopen("1.in", "r", stdin);
    int N;
    double total = 0;
    double num = 0;
    while(cin>>N){
        total+=N;
        num++;
    }
    double check = total/num - (int)(total/num);
    if(check > 0.5){
        cout<<int(total/num + 1)<<endl;
    }else if(check == 0.5){
        cout<<int(total/num)<<' '<<int(total/num+1)<<endl;
    }else{
        cout<<int(total/num)<<endl;
    }
    exit(0);
}
