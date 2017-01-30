/*
ID: j316chuck
PROG: nocows
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
using namespace std;

int N, K;
int perm[201][101];
int mem[201][101][101];

/*int Recurse(int height, int nodes, int previous_nodes){
    //cout<<"new"<<nodes<<' '<<height<<' '<<previous_nodes<<endl;
    //cout<<mem[nodes][height]<<endl;
    if(mem[nodes][height]!=0){
        //cout<<"finished"<<endl;
        return mem[nodes][height];
    }if(nodes%2 == 0){
        return 0;
    }else if(nodes < 5 || height < 3){
        //cout<<"failed"<<endl;
        return 0;
    }else{
        //cout<<"hello"<<endl;
        int total = 0;
        for(int i = ((previous_nodes/2+1)/2)*2; i < nodes; i+=2){
            mem[nodes-i][height-1] =Recurse(height-1, nodes-i, i) * perm[][]% 9901;
            //cout<<mem[nodes-i][height-1]<<' '<<nodes-i<<' '<<height-i<<' '<<perm[nodes-i][height-1]<<endl;
            total = total % 9901;
        }
        mem[nodes][height] = total;
        //cout<<"new mem "<<mem[nodes][height]<<' '<<nodes<<' '<<height<<endl;
        return mem[nodes][height];
    }

}
*/
int total;
void Recurse(int height, int nodes, int curr_nodes, int result){
    if(height == K && nodes == N){
        //mem[N][K]+=result % 9901;
        total+= result;
        total = total% 9901;
        return;
    }else if(nodes > N || height > K){
        return;
    }/*else if(mem[nodes][height]!=0){
        return mem[nodes][height];
    }*/
    else{
        for(int i = 2; i <= curr_nodes*2; i+=2){
            Recurse(height+1, nodes+i, i, (result*perm[curr_nodes][i/2])%9901);
        }
    }
}
int main(){

    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    cin>>N>>K;

    for(int i = 0; i < 201; i++){
        perm[i][0] = 1;
    }for(int i = 1; i < 101; i++){
        perm[0][i] = 0;
    }
    for(int i = 1; i < 201; i++){
        for(int k = 1; k <= i && k < 101; k++){
            perm[i][k] = (perm[i-1][k-1] + perm[i-1][k]) % 9901;
        }
    }
    mem[3][2][2] = 1;
    mem[1][1][1] = 1;
    mem[5][3][2] = 2;
    mem[7][3][4] = 1;

    //cout<<mem[200][100][100]<<endl;//nodes, height
    //int R = Recurse(K+1, N+2, 2);
    //Recurse(1, 1, 1, 1);
    //cout<<total<<endl;
    /*int nodes = 1, height = 1, curr_nodes = 1, path = 1;
    while(nodes <= N && height <= K){
        for(int i = 2; i < N; i++){

        }
    }*/
    //4 finished by 4 :) and then 5 :) finished :)) 5 8 :)int curr_nodes = 1, path = 1;
    //mem[1][1] = 1; curr_nodes=3
    for(int height = 4; height <= 100; height++){
        for(int curr_node = 3; curr_node <=200; curr_node+=2){ //amount
            for(int past_node = 2; past_node <= 100; past_node+=2){ //previous
                if(mem[curr_node][height-1][past_node] != 0){
                    for(int node = 2; node <= past_node*2 && node+curr_node <= 200; node+=2){
                        mem[node+curr_node][height][node] += (mem[curr_node][height-1][past_node]*perm[past_node][node/2]) % 9901;
                        //mem[node+curr_node][height][node] = (mem[curr_node][height-1][past_node]*perm[past_node][node/2]) % 9901;
                        mem[node+curr_node][height][node] = mem[node+curr_node][height][node] % 9901;
//cout<<curr_node<<' '<<height-1<<' '<<past_node<<' '<<mem[curr_node][height-1][past_node]<<' '<<mem[node+curr_node][height][node] <<endl;

                    }
                }
            }
        }
    }
    total = 0;
    /*for(int height = 1; height <= 100; height++){
        for(int curr_node = 3; curr_node <=200; curr_node+=2){ //amount
            for(int past_node = 2; past_node <= 100; past_node+=2){ //previous
                if(mem[curr_node][height][past_node] != 0)
                    cout<<mem[curr_node][height][past_node]<<' '<<curr_node<<' '<<height<<' '<<past_node<<endl;
            }
        }
    }*/
    /*for(int height = 1; height <= 100; height++){
        for(int curr_node = 3; curr_node <=200; curr_node+=2){
            int total = 0; //amount
            for(int past_node = 2; past_node <= 100; past_node+=2){ //previous
                if(mem[curr_node][height][past_node] != 0){
                    total+=mem[curr_node][height][past_node];
                    total= total%9901;
                }
            }
            if(total!=0)
                cout<<curr_node<<' '<<height<<' '<<total<<endl;
        }
    }*/
    for(int i = 0; i <= 100; i++){
        if(mem[N][K][i]!=0){
            //cout<<mem[N][K][i]<<' '<<i<<' ';
            total += mem[N][K][i];
            total = total % 9901;
        }
    }    //cout<<mem[N][K]<what<endl;
    cout<<total<<endl;
}
