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

int main(){
    Wt("output.txt");
    vector<int> mygraph;
    mygraph.push_back(1);
    int num=1;
    for(int i=1; i<10; i++){
        num*=i;
    }
    for(int i=1; i<7; i++){
        mygraph.push_back(num%10);
        num=num/10;
    }
    reverse(mygraph.begin(), mygraph.end());
    mygraph.erase(mygraph.end()-1);
    /*for(int i=0; i<mygraph.size(); i++){
        cout<<mygraph[i];
    }*/
    for(int i=10; i<100; i++){
        int one=i%10;
        int two=i/10;
        vector<int> onegraph;
        int carry=0;
        for(int k=mygraph.size()-1; k>=0; k--){
            int dig=(one*mygraph[k]+carry)%10;
            carry=(one*mygraph[k]+carry)/10;
            onegraph.push_back(dig);
        }
        if(carry!=0){
            onegraph.push_back(carry);
        }
        reverse(onegraph.begin(), onegraph.end());

        vector<int> twograph;
        carry=0;
        for(int k=mygraph.size()-1; k>=0; k--){
            int dig=(two*mygraph[k]+carry)%10;
            carry=(two*mygraph[k]+carry)/10;
            twograph.push_back(dig);
        }
        if(carry!=0){
            twograph.push_back(carry);
        }
        reverse(twograph.begin(), twograph.end());
        twograph.push_back(0);

        mygraph.clear();

        for(int i=0; i<twograph.size()-onegraph.size(); i++){
            onegraph.insert(onegraph.begin(), 0);
        }
        carry=0;
        for(int i=twograph.size()-1; i>=0; i--){
            int dig=(twograph[i]+onegraph[i]+carry)%10;
            carry=(twograph[i]+onegraph[i]+carry)/10;
            mygraph.push_back(dig);
        }
       if(carry!=0){
        mygraph.push_back(carry);
       }
       reverse(mygraph.begin(), mygraph.end());
        /*for(int i=0; i<mygraph.size(); i++){
            cout<<mygraph[i];
        }cout<<endl;*/
    }
    int sum=0;
    for(int i=0; i<mygraph.size(); i++){
        cout<<mygraph[i];
    }
    cout<<endl;
    for(int i=0; i<mygraph.size(); i++){
        sum+=mygraph[i];
    }
    cout<<sum<<endl;
}
