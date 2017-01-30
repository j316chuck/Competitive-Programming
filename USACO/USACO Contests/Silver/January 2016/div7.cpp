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


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;

int main(){
    Rd("div7.in");
    Wt("div7.out");
    int N;
    cin>>N;
    vector<long long> mysum;
    long long sum=0;
    mysum.push_back(0);
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        sum+=k;
        mysum.push_back(sum);
    }
    /*for(int i=0; i<=N; i++){
        cout<<mysum[i]<<' ';
    }*/
    //cout<<mysum.size();
    //int test=0;
    int random=0;
    for(int i=N; i>=0; i--){
        for(int k=0; k+i<=N; k++){
            //cout<<mysum[k+N]<<' '<<mysum[k]<<endl;
            if((mysum[k+i]-mysum[k])%7==0){
                cout<<i<<endl;
                random=1;
                break;
            }
        }
        if(random==1){
             break;
        }
    }
}
