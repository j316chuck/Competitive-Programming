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
    int R=(myarray[N-1]-myarray[0])/(K)+1;
    R=R/2+1;
    int mynum=1000000001;
    int pos=0;
    int counter=0;
    while(counter==0){
        mynum=myarray[0];
        for(int i=0; i<K; i++){
            mynum+=2*R;
            if(i!=K-1){
                for(int k=pos; k<myarray.size(); k++){
                    if(myarray[k]>mynum){
                        mynum=myarray[k];
                        pos=k;
                        break;
                    }
                }
            }else{
                if(myarray[N-1]-myarray[pos]<2*R){
                    R--;
                }else{
                    cout<<R+2<<endl;
                    counter++;
                }
            }
        }
        //mynum=1000000001;
    }
}
