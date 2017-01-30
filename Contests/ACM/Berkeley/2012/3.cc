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

int W, H;
vector<int> top;
vector<int> bottom;
vector<int> left;
vector<int> right;

vector<string> mygraph;

/*bool check_over(vector<int> a, vector<int> b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == -1)
            continue;
        else if(a[i]<b[i]){
            return false;
        }
    }
    return true;
}*/

/*bool check_filled(vector<string> graph){
    for(int i = 0; i <mygraph.size(); i++){
        for(int j = 0; j <mygraph[i].size(); j++){
            if(mygraph[i][j] == 'L'|| mygraph[i][j]=='R' || mygraph[i][j] == 'B'||mygraph[i][j] == 'T'){
                return false;
            }
        }
    }
    return true;
}*/

bool check_good(vector<int> u, vector<int> d, vector<int> r, vector<int> l){
    for(int i = 0; i < top.size(); i++){
        if(top[i] == -1)
            continue;
        else if(top[i] < u[i])
            return false;
    }for(int i = 0; i < bottom.size(); i++){
        if(bottom[i] == -1)
            continue;
        else if(bottom[i] < d[i])
            return false;
    }for(int i = 0; i < right.size(); i++){
        if(right[i] == -1)
            continue;
        else if(right[i] < r[i])
            return false;
    }for(int i = 0; i < left.size(); i++){
        if(left[i] == -1)
            continue;
        else if(left[i] < l[i])
            return false;
    }
    return true;
}

int total_tiles;
int total_counter;

bool check_recurse(vector<string> mygraph, char dir, int r, int c, char sign){

    int r1 = r, c1 = c, r2, c2;
    if(dir == 'L'){
        r2 = r1;
        c2 = c1 + 1;
    }else if(dir == 'R'){
        r2 = r1;
        c2 = c1 - 1;
    }else if(dir == 'T'){
        c2 = c1
        r2 = r2+1;
    }else if(dir == 'B'){
        c2 = c1
        r2 = r2+1;
    }

    if(sign == '+'){
        if(r1-1 >= 0){

        }if(r1+1 < )
    }else{

    }
}

void Recurse(vector<string> mygraph, int tiles){
    vector<int> l;
    vector<int> r;
    vector<int> u;
    vector<int> d;
    for(int i = 0; i < mygraph.size(); i++){
        int negative = 0, positive = 0;
        for(int k = 0; k < mygraph[i].size(); k++){
            if(mygraph[i][k] == '-')
                negative++;
            else if(mygraph[i][k] == '+')
                positive++;
        }
        l.push_back(positive);
        r.push_back(negative);
    }
    for(int k = 0; k < mygraph[0].size(); k++){
        int negative = 0, positive = 0;
        for(int i = 0; i < mygraph.size(); i++){
            if(mygraph[i][k] == '-')
                negative++;
            else if(mygraph[i][k] == '+')
                positive++;
        }
        u.push_back(positive);
        d.push_back(negative);
    }
    if(tiles == total_tiles){
        if(l == left && u == up && d == bottom && r == right){
            cout<<"Set "<<total_counter++<<":"<<endl;
            for(int i = 0; i <mygraph.size(); i++){
                cout<<"   "<<mygraph[i]<<endl;
            }cout<<endl;
        }else{
            return;
        }
    }else if(check_good(u, d, l, r)){
        int r  = -1, c = -1;
        for(int i = 0; i < mygraph.size(); i++){
            for(int k = 0; k < mygraph[0].size(); k++){
                if(mygraph[i][k]=='L'||mygraph[i][k]=='R'||mygraph[i][k]=='T'||mygraph[i][k]=='B')
                    r = i;  c = k; break;
            }
            if(r!=-1 && c!=-1)
                break;
        }
        if(check_recurse(mygraph, mygraph[r][c], r, c, '+')){

        }if(check_recurse(mygraph, mygraph[r][c], r, c, '-')){

        }
        Recurse(mygraph)
    }

}
int main(){

    freopen("3.in", "r", stdin);

    while(cin>>W>>H){
        mygraph.clear(); top.clear(); bottom.clear();
        left.clear();right.clear();
        total_tiles = W*H;
        for(int i = 0; i < W; i++){
            int a;
            cin>>a;
            top.push_back(a);
        }for(int i = 0; i < W; i++){
            int a;
            cin>>a;
            bottom.push_back(a);
        }for(int i = 0; i < H; i++){
            int a;
            cin>>a;
            left.push_back(a);
        }for(int i = 0; i < H; i++){
            int a;
            cin>>a;
            right.push_back(a);
        }
        for(int i = 0; i < W; i++){
            string temp;
            cin>>temp;
            mygraph.push_back(temp);
        }
        Recurse(mygraph, 0);
    }
    exit(0);
}
