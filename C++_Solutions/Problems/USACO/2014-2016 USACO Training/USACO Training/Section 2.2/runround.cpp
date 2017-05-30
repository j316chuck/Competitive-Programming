/*ID: j316chuck
PROG: runround
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

int c[10];
int N;

int visit(int pos, string result){
    return ((result[pos] - '0' + pos) % result.size());
}

bool check(int a){
    ostringstream convert;
    convert<<a;
    string result = convert.str();
    memset(c, 0, sizeof(c));
    int start = 0;
    int pos = 0;
    for(int i = 0; i < result.size(); i++){
        if(c[pos] != 0){
            return false;
        }else{
            c[pos] = 1;
            pos = visit(pos, result);
            if (i == result.size()-1){
                if(pos == 0)
                    return true;
                else
                    return false;
            }
        }
    }
}

void next_num(int length, string result, int arr[]){
    if(result.size() == length){
        int value = atoi(result.c_str());
        if(value <= N)
            return;
        if(check(value)){
            cout<<value<<endl;
            exit(0);
            return;
        }
    }else{
        for(int i = 1; i <= 9; i++){
            if (arr[i] == 0){
                arr[i] = 1;
                ostringstream convert;
                convert<<i;
                next_num(length, result+convert.str(), arr);
                arr[i] = 0;
            }
        }
    }
}

int main(){

    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    cin>>N;

    int k = log10(N);
    for(int i = k + 1; i <= 9; i++){
        int arr[10];
        memset(arr, 0, sizeof(arr));
        next_num(i, "" , arr);
    }

    /*for(int i = 0; i < 10; i++)
        cout<<myints[i];
    cout<<endl;
    while(next_permutation(myints, myints+9)){
        for(int i = 0; i < 9; i ++){
            cout<<myints[i];
        }cout<<endl;
    }*/ //next_permutation
}
