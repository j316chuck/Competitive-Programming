
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

vector<int> myvector;
int main(){
   Rd("angry.in");
   Wt("angry.out");
   int N,K;
   cin>>N>>K;
   for(int i=0; i<N; i++){
        int a;
        cin>>a;
        myvector.push_back(a);
   }
   sort(myvector.begin(), myvector.end());
   //cout<<myvector[0]<<endl;
   int bot=myvector[0];
   int top=myvector[myvector.size()-1];
   int min=1000000001;
   while(bot<=top){
        int mid=(bot+top)/2;
        int b=myvector[0];
        bool works=false;
        for(int i=0; i<K; i++){
            b+=2*mid+1;
            for(int k=0; k<myvector.size(); k++){
                if(b<=myvector[k]){
                    b=myvector[k];
                    break;
                }if(k==myvector.size()-1){
                    works=true;
                    break;
                }
            }
            if(works==true){
                break;
            }
        }
        if(works==true){
            //cout<<bot<<' '<<top<<' '<<min<<endl;
            top=mid-1;
            min=mid;
        }else{
            //cout<<bot<<' '<<top<<' '<<min<<endl;
            bot=mid+1;
        }
   }
   cout<<min<<endl;
}
