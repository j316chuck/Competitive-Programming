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
int company[101][101];
int visited[101][101];

void update(int A, int B){

    for(int i = 0; i < 101; i++){
        if(company[B][i] >= 100)
            company[B][i] = 100;

        company[A][i]+=company[B][i];

        if(company[A][i] >= 100)
            company[A][i] == 100;
    }
}

int main(){

    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    cin>>N;
    for(int i = 0; i < N; i++){
        int a, b, perc;
        cin>>a>>b>>perc;
        company[a][b] = perc;
    }

    bool not_equal = true;

    while(not_equal){

        int old_visited[101][101];

        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                old_visited[i][j] = visited[i][j];
            }
        }

        not_equal = false;

        for(int i = 1; i < 101; i++){
            for(int j = 1; j < 101; j++){
                if(company[i][j] > 50 && visited[i][j] == 0){
                    update(i, j);
                    visited[i][j] = 1;
                    not_equal = true;
                    for(int k = 1; k < 101; k++){
                        if(visited[k][i] == 1 && visited[k][j] == 0){
                            update(k, j);
                            visited[k][j] = 1;
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <101; i++){
        for(int j = 1; j < 101; j++){
            if(company[i][j] > 50 && i!=j)
                cout<<i<<' '<<j<<endl;
        }
    }
}

