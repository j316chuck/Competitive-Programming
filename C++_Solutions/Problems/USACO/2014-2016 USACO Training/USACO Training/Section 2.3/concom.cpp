/*
ID: j316chuck
PROG: concom
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

int N;
int company[101][101]; //[A] owns [B]

void update(int A, int B){
    for(int i = 1; i <= 100; i++){
        company[A][i]+=company[B][i];
    }
}

void Recurse(int A){
    bool visited[101];
    memset(visited, 0, sizeof(visited));
    int temp = 1;
    /*cout<<A<<endl;
    for(int i = 1; i <=3; i++){
        for(int j = 1; j<=3; j++){
            cout<<company[i][j]<<' ';
        }cout<<endl;
    }*/
    while(temp == 1){
        temp = 0;
        for(int B = 1; B <= 100; B++){
            //cout<<B<<' ';
            if(company[A][B] > 50 && visited[B] == false){
                Recurse(B);
                update(A, B);
                visited[B] = true;
            }
        }
        for(int B = 1; B <= 100; B++){
             if(company[A][B] > 50&&visited[B]== false){
                temp = 1;
                break;
             }
        }

    }
    return;
}

int main(){

    freopen("concom.in", "r", stdin);
    //freopen("concom.out", "w", stdout);
    cin>>N;
    for(int i = 0; i < N; i++){
        int a, b, perc;
        cin>>a>>b>>perc;
        company[a][b] = perc;
    }

    for(int i = 1; i <= 3; i ++){
        Recurse(i);
    }
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            cout<<company[i][j]<<' ';
        }//cout<<endl;
    }
    /*for(int i = 0; i < N; i++){
        cout<<myvector[i].A<<' '<<myvector[i].B<<' '<<myvector[i].per<<endl;
    }*/
}
