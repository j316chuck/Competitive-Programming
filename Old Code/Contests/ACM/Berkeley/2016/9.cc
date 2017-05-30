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

int N, M;
int startx, starty;
vector<string> mygraph;
int minimum;
int top, down, le, ri;
bool check(vector<string> graph){
    int counter=0;
    for(int i = 0; i < M; i++){
        if(graph[top][i] == '1' || graph[top][i] == 'F'|| graph[top][i] == '2'){
            counter++;
            break;
        }
    }for(int i = 0; i < M; i++){
        if(graph[down][i] == '1' || graph[down][i] == '2' || graph[down][i] == 'F'){
            counter++;
            break;
        }
    }for(int i = 0; i < N; i++){
        if(graph[i][le] == '1' ||  graph[i][le] == '2' || graph[i][le] == 'F'){
            counter++;
            break;
        }
    }for(int i = 0; i < N; i++){
        if(graph[i][ri] == '1' || graph[i][ri] == '2' || graph[i][ri] == 'F'){
            counter++;
            break;
        }
    }
    /*for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<graph[i][j];
        }cout<<endl;
    }*/
    //cout<<startx<<' '<<starty<<endl;
    if(counter == 4){
        //cout<<"true"<<" "<<counter<<top<<' '<<down<<' '<<le<<' '<<ri<<endl;
        return true;
    }else{
        //cout<<"false"<<endl;
        return false;
    }

}
/*bool surround(vector<string> mygraph){
    for(int i = 0; i < mygraph.size(); i++)
        cout<<mygraph[i]<<endl;
    if(startx-1 >= 0){
        if(mygraph[startx-1][starty] != 'W' && mygraph[startx-1][starty]!='X')
            return true;
    }if(startx+1 < N){
        if(mygraph[startx+1][starty]!= 'W' && mygraph[startx+1][starty]!='X')
            return true;
    }if(starty-1 >= 0){
        if(mygraph[startx][starty-1]!='W' && mygraph[startx][starty-1]!='X')
            return true;
    }if(starty+1 < M){
        if(mygraph[startx][starty+1]!='W' && mygraph[startx][starty+1]!='X'){
            return true;
        }
    }
    //cout<<mygraph[startx][starty+1]<<' '<<mygraph[startx][starty-1]<<' '<<mygraph[startx-1][starty]<<' '<<mygraph[startx+1][starty]<<endl;
    //cout<<startx<<' '<<starty<<endl;
    return false;
}*/

void Recurse(int r, int c, int length, vector<string> graph){
    if(r >= N || r < 0 || c < 0 || c >= M){
        return;
    }if(graph[r][c]=='F'){
        //cout<<"hello"<<endl;
        if(check(graph))
            minimum = min(minimum, length);
        return;
    }if(graph[r][c] == 'W'){
        return;
    }if(minimum <= length){
        return;
    }if(graph[r][c] == '2'){
        return;
    }if(graph[r][c] == 'S'){
        graph[r][c] ='F';
    }/*if(surround(graph) == 0 && length == 2){
        return;
    }*/
    char old = mygraph[r][c];
    if(graph[r][c]== '1')
        graph[r][c] = '2';
    else if(graph[r][c] == '.')
        graph[r][c] ='1';
    /*cout<<"LENGTH : "<<length<<" MINIMUM: "<<minimum<<"SURROUND: "<<surround(graph)<<endl;
    for(int i = 0; i < N; i++)
        cout<<graph[i]<<endl;*/
    Recurse(r, c+1, length+1, graph);
    Recurse(r, c-1, length+1, graph);
    Recurse(r+1, c, length+1, graph);
    Recurse(r-1, c, length+1, graph);

    //graph[r][c] = old;
    return;

}
int main(){
    //freopen("9.in", "r", stdin);
    //freopen("9.out", "w",stdout);
    /*startx = 0, starty = 0;
    vector<string> test;
    test.push_back("SWW");
    test.push_back("WWW");
    test.push_back("WWW");*/
    //N = 3, M = 3;
    //cout<<surround(test)<<endl;

    while(cin>>N>>M){
        mygraph.clear();
        minimum = 100001;
        top = 10000, le = 1000;
        down = -1, ri = -1;
        for(int i = 0; i < N; i++){
            string s;
            cin>>s;
            mygraph.push_back(s);
            for(int j = 0; j < M; j++){
                if(s[j] == 'W'){
                    top = min(i, top);
                    down= max(i, down);
                    ri = max(j, ri);
                    le = min(j, le);
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(mygraph [i][j] == 'S'){
                    startx = i;
                    starty = j;
                }
            }
        }
        //cout<<startx<<' '<<starty<<' '<<top<<' '<<down<<' '<<ri<<' '<<le<<endl;
        if(top -1 < 0 || down+1 >= N || le-1 < 0 || ri + 1 >=M){
            cout<<-1<<endl;
        }else{
            top--;
            down++;
            ri++;
            le--;
            Recurse(startx, starty, 0, mygraph);
            //cout<<minimum<<endl;
            if(minimum == 100001)
                cout<<-1<<endl;
            else
                cout<<minimum<<endl;
        }
    }
    exit(0);
}
