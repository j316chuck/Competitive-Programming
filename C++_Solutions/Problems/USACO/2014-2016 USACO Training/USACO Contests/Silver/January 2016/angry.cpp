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

    Rd("angry.in");
    Wt("angry.out");
    int N, K;
    cin>>N>>K;
    vector<int> myarray;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        myarray.push_back(a);
    }
    sort(myarray.begin(), myarray.end());
    int top=myarray[N-1];
    int bot=myarray[0];
    int increment=(myarray[N-1]-myarray[0])/K+1;
    int remainder=(myarray[N-1]-myarray[0])%K;
    int pos=0;
    int maximum=0;
    for(int i=0; i<K; i++){
        int start=pos;
        int end=bot+increment*(i+1);

        if(i!=K-1){
           while(myarray[0]!=-1){
                if(myarray[pos]<end){
                    pos++;
                }else{
                    int diff=myarray[pos-1]-myarray[start];
                    maximum=max(maximum, (diff+1)/2);
                    break;
                }
            }
        }else{
            int diff=myarray[N-1]-myarray[start];
            maximum=max(maximum, (diff+1)/2);
        }
    }
    cout<<maximum<<endl;
}
