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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int matrix[101][101];

int main(){

    //freopen("poj_1050.in", "r", stdin);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
        }
    }
    int maximum = 0;
    int temp[101];

    for(int i = 0; i < n; i++){ //rows
        for(int j = 0; j < n; j++) //initialize
            temp[j] = 0;

        for(int j = i; j < n; j++){ //rows starting from row i
            int sum = 0, m = 0;
            for(int k = 0; k < n; k++){ //columns update
                temp[k] += matrix[j][k];
            }
            for(int k = 0; k < n; k++){ //greedy algorithm
                if(sum <= 0){
                    sum = temp[k];
                }else{
                    sum += temp[k];
                }
                m = max(sum, m);
            }
            maximum = max(maximum, m);
        }
    }
    cout<<maximum<<endl;
}

