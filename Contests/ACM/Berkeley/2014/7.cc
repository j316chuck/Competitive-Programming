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

using namespace std;

vector< vector<int> > mygraph;

#define HM 1000000007
#define HA 100000007
#define HB 101


/*int visited(vector< vector<int> > graph){
    int sum = 0;
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            sum+=(((i+1)*mygraph[i][j] * HA + ch + HB) % HM);
            sum = sum % HM;
        }
        sum = sum % HM;
    }
}*/

int visited[5][3126];

void calc_visited(vector< vector<int> > mygraph){
    for(int i = 0; i < mygraph.size(); i++){
        for(int j = 0; j < mygraph[i].size(); j++){
            int total = 0;
            total+=pow(5, j)*mygraph[i][j];
            visited[i][total] = 1;
        }
    }
}

bool visited(vector< vector<int> > mygraph){
    for(int i = 0; i < mygraph.size(); i++){
        for(int j = 0; j < mygraph[i].size(); j++){
            int total = 0;
            total+=pow(5, j)*mygraph[i][j];
            if(visited[i][total] == 0){
                return false;
            }
        }
    }
    return true;
}

int main(){

    freopen("7.in", "r", stdin);

    int a;

    while(cin>>a){
        for(int i = 0; i < 5; i++){
            vector<int> temp;
            for(int j = 0; j < 5; j++){
                if(i == 0 && j == 0){
                    temp.push_back(a);
                    continue;
                }
                cin>>a;
                temp.push_back(a);
            }mygraph.push_back(temp);
        }
        for(int i = 0; i < mygraph.size(); i++){
            for(int j = 0; j < mygraph[i].size(); j++){
                cout<<mygraph[i][j]<<' ';
            }cout<<endl;
        }
        //cout<<visited[4][3125]<<endl;
        for(int i = 0; i < mygraph.size(); i++){

        }
    }
}
