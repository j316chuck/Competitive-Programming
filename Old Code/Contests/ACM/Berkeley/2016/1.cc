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

int N, s_x, s_y, e_x, e_y;
int mem[1001][1001];
int minimum;
void Recurse(int x, int y, int length){
    if(x >= N || x <0 || y >= N || y < 0){
        return;
    }if(x == e_x && y == e_y){
        if(mem[x][y] != -1){
            mem[x][y] = min(mem[x][y], length);
            minimum = mem[x][y];
        }else{
            mem[x][y] = length;
            minimum = length;
        }
        return;
    }if(mem[x][y] != -1 && mem[x][y] <= length){
        return;
    }if(minimum < length){
        return;
    }if(mem[x][y] == -1){
        mem[x][y] = length;
    }if(mem[x][y] != -1 && mem[x][y] > length){
        mem[x][y] = length;
    }
    int distancex = e_x-x;
    int distancey = e_y-y;
    //cout<<x<<' '<<y<<' '<<length<<' '<<distancex<<' '<<distancey<<endl;

    if(abs(distancex)+ abs(distancey) <= 8){
    Recurse(x+2, y+1, length+1);
    Recurse(x+2, y-1, length+1);
    Recurse(x+1, y+2, length+1);
    Recurse(x+1, y-2, length+1);
    Recurse(x-2, y+1, length+1);
    Recurse(x-2, y-1, length+1);
    Recurse(x-1, y+2, length+1);
    Recurse(x-1, y-2, length+1);
    }else if(distancex >=0 && distancey >=0){
        Recurse(x+1, y+2, length+1);
        Recurse(x+2, y+1, length+1);
    }else if(distancex < 0 && distancey >= 0){
        Recurse(x-1, y+2, length+1);
        Recurse(x-2, y+1, length+1);
    }else if(distancex >=0 && distancey <0){
        Recurse(x+1, y-2, length+1);
        Recurse(x+2, y-1, length+1);
    }else{
        Recurse(x-1, y-2, length+1);
        Recurse(x-2, y-1, length+1);
    }
    return;
}

int main(){
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    while(cin>>N>>s_x>>s_y>>e_x>>e_y){
        minimum = 10000;
        memset(mem, -1, sizeof(mem));
        Recurse(s_x, s_y, 0);
        cout<<mem[e_x][e_y]<<endl;
    }
    exit(0);
}
