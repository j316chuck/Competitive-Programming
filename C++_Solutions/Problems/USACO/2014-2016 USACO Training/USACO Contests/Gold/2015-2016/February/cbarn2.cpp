/*ID: j316chuck
PROG: cbarn
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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;


bool check(vector< vector<int> > arr){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].size()!=1){
            return false;
        }
    }return true;
}
int main(){

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin>>n;
    vector< vector<int> > cows;
    int unvisited = 0;
    for(int i = 0; i < n; i++){
        int a; cin>>a;
        vector<int> temp;
        for(int k = 0; k < a; k++){
            temp.push_back(0);
        }
        if(a == 0){
            unvisited++;
        }
        cows.push_back(temp);
    }
    while(unvisited!=0){
        /*for(int i = 0; i < n; i++){
            cout<<cows[i].size()<<' ';
        }cout<<endl;*/

        for(int i = 0; i < n; i++){
            sort(cows[i].begin(), cows[i].end());
            if(i != n-1){
                if(!cows[i].empty() && cows[i+1].empty()){
                    int least = cows[i][0];
                    cows[i].erase(cows[i].begin());
                    cows[i+1].push_back(++least);
                    if(!cows[i].empty()){
                        unvisited--;
                    }
                }
            }else{
                if(!cows[i].empty() && cows[0].empty()){
                    int least = cows[i][0];
                    cows[i].erase(cows[i].begin());
                    cows[0].push_back(++least);
                    if(!cows[i].empty()){
                        unvisited--;
                    }
                }
            }
        }
    }
    long long result = 0;
    for(int i = 0; i < n; i++){
        if(cows[i].size()!=1){
            cout<<"error"<<endl;
        }else{
            result+=cows[i][0]*cows[i][0];
        }
    }
    cout<<result<<endl;
}
