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

vector<int> mygraph;
class three{
public:
    int o;
    int t;
    int thr;
};
int one1, two1, three1;
vector< vector<three> > check;

void sum(int start, int end){
    if(start==end+1)
        return;
    if(start%10000==0&&start+9999<=end){
        one1+=check[4][start].o;
        two1+=check[4][start].t;
        three1+=check[4][start].thr;
        sum(start+10000, end);
        return;
    }else if(start%100==0&&start+99<=end){
        one1+=check[2][start].o;
        two1+=check[2][start].t;
        three1+=check[2][start].thr;
        sum(start+100, end);
        return;
    }else{
        one1+=check[0][start].o;
        two1+=check[0][start].t;
        three1+=check[0][start].thr;
        sum(start+1, end);
        return;
    }
}
int main(){
    Rd("bcount.in");
    Wt("bcount.out");
    int N, Q;
    cin>>N>>Q;

    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        mygraph.push_back(a);
    }

    for(int i=0; i<5; i+=2){
        int incr=pow(10,i);
        vector<three> temp;
        if(incr<N){
            for(int k=0; k<N; k+=incr){
                three a; a.o=0; a.t=0; a.thr=0;
                if(k+incr<=N){
                     for(int j=k; j<k+incr; j++){
                    //if(j<N){
                         if(mygraph[j]==1){
                            a.o++;
                        }if(mygraph[j]==2){
                            a.t++;
                        }if(mygraph[j]==3){
                            a.thr++;
                        }
                    //}
                    }
                }
                temp.push_back(a);
            }
        }check.push_back(temp);
    }

    /*for(int i=0; i<check.size(); i++){
        for(int k=0; k<check[i].size(); k++){
            cout<<check[i][k].o<<check[i][k].t<<check[i][k].thr<<' ';
        }cout<<endl;
    }*/
    for(int i=0; i<Q; i++){
        int a, b;
        cin>>a>>b;
        //cout<<a<<b<<endl;
        a=a-1;b=b-1;
        one1=0; two1=0; three1=0;
        sum(a,b);
        cout<<one1<<' '<<two1<<' '<<three1<<endl;
    }


}


