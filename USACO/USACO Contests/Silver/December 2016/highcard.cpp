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
using namespace std;

vector<int> myarray;
vector<int> hisarray;
int mytemp[100001];
int main(){
    Rd("highcard.in");
    //Wt("highcard.out");
    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        hisarray.push_back(a);
        mytemp[a]=1;
    }
    for(int i=1; i<=2*N; i++){
        if(mytemp[i]==0)
            myarray.push_back(i);
    }
    sort(hisarray.begin(), hisarray.end());
    for(int i=N; i>=0; i--){
        if(i!=N){
            myarray.push_back(myarray[0]);
            myarray.erase(myarray.begin());
        }
        int counter=0;
        for(int k=0; k<N-1; k++){
            if(myarray[k]>hisarray[k]){
                counter++;
            }
        }
        if(counter==i){
            cout<<counter<<endl;
            break;
        }if(i==0){
            cout<<'0'<<endl;
        }

    }


}
