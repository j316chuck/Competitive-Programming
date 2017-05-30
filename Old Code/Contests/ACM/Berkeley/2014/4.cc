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

int skip[5001];

double num, denom;
int N;

int minimum;
vector<int> answer;
int mem[5000][5000];

//long long loop_iteration;

void Recurse(double sum, double last_value, vector<int> result, int counter, long times){
    //loop_iteration++;
    //cout<<loop_iteration<<' '<<sum<<' '<<last_value<<' '<<counter<<endl;
    if(times > pow(10,7)){
       return;
    }
    if(counter >= minimum ){
        return;
    }else{
        counter++;
    }
    if(sum > num){
        return;
    }
    for(int i = last_value; i <= 5000; i++){
        if(skip[i]==1)
            continue;
        else if(num - (sum + denom/i) == 0){
            minimum = counter;
            result.push_back(i);
            //cout<<num<<minimum<<' '<<result[0]<<' '<<result[1]<<' '<<sum+denom/i<<endl;
            answer.clear();
            for(int i = 0; i < result.size(); i++){
                answer.push_back(result[i]);
                //cout<<answer[i]<<' ';
            }//cout<<endl;
            return;
        }else{
            if(counter >= minimum)
                return;
            result.push_back(i);
            Recurse(sum+denom/i, i+1, result, counter, times*i);
            result.pop_back();
        }
    }
    return;
}

int gcd(int a, int b){
    if(mem[a][b] != 0)
        return mem[a][b];
    else{
        if(a == 0){
            mem[a][b] = b;
            return b;
        }else{
            mem[a][b] = gcd(b%a, a);
            return mem[a][b];
        }
    }
}
void initiate(){
    for(int i = 1; i <=5000; i++){
        for(int j =1; j<=5000; j++){
            mem[i][j] = gcd(i,j);
            //cout<<mem[i][j]<<endl;
        }
    }
    return;
}
int main(){
    freopen("4.in", "r", stdin);
    int counter = 0;

    while(cin>>num>>denom>>N){
        memset(skip, 0, sizeof(skip));
        counter++;
        minimum = 5002;
        //cout<<mem[13][45]<<endl;
        for(int i = 0; i < N; i++){
            int a; cin>>a; skip[a] = 1;
        }
        /*if(counter == 1)
            initiate();
        //cout<<"hello"<<endl;
        /*for(int i = 2; i < N; i++){
            if(mem[i][int(denom)]/i == 1 && i > 20)
                skip[i] = 1;
        }*/
        vector<int> result;
        result.clear();
        //answer.clear();
        Recurse(0, 2, result, 0, 1);
        /*for(int i = 0; i < result.size(); i++)
            cout<<result[i]<<' ';*/
        cout<<"Case "<<counter<<": "<<num<<"/"<<denom<<"-";
        for(int j = 0; j < answer.size(); j++){
            if(j == answer.size()-1){
                cout<<"1/"<<answer[j]<<endl;
            }else
                cout<<"1/"<<answer[j]<<'+';
        }
    }
}
