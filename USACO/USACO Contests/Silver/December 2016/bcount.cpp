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
int main(){
    Rd("bcount.in");
    Wt("bcount.out");
    int N, Q;
    cin>>N>>Q;
    if(N<10000){
         for(int i=0; i<N; i++){
        int a;
        cin>>a;
        mygraph.push_back(a);
    }
    vector< vector<three> > myarray;

    for(int i=0; i<N; i++){
        three a; a.o=0; a.t=0; a.thr=0;
        vector<three> temp;
        for(int k=i; k<N; k++){
            if(mygraph[k]==1){
                a.o++;
            }if(mygraph[k]==2){
                a.t++;
            }if(mygraph[k]==3){
                a.thr++;
            }
            temp.push_back(a);
        }
        myarray.push_back(temp);
    }
    /*for(int k=0; k<myarray.size(); k++){
        for(int i=0; i<myarray[k].size(); i++){
            cout<<myarray[k][i].o<<myarray[k][i].t<<myarray[k][i].thr<<' ';
        }cout<<endl;
    }*/
    for(int i=0; i<Q; i++){
        int a,b;
        cin>>a>>b;
        a=a-1; b=b-1;
        cout<<myarray[a][b-a].o<<' '<<myarray[a][b-a].t<<' '<<myarray[a][b-a].thr<<endl;
    }
    }else{

        for(int i=0; i<N; i++){
        int a;
        cin>>a;
            mygraph.push_back(a);
        }
        vector< vector<three> > check;
        for(int i=0; i<6; i++){
            int incr=pow(10,i);
            vector<three> temp;
            if(incr<N){
                three a; a.o=0; a.t=1; a.thr=2;
                for(int k=0; k<N; k+=incr){
                    for(int j=0; j<k; j++){
                         if(mygraph[j]==1){
                            a.o++;
                        }if(mygraph[j]==2){
                            a.t++;
                        }if(mygraph[j]==3){
                            a.thr++;
                        }
                    }
                }temp.push_back(a);
            }
        }

    }

        /*int c1=0;
        int c2=0;
        int c3=0;
        for(int k=a-1; k<=b-1; k++){
            if(mygraph[k]==1){
                c1++;
            }if(mygraph[k]==2){
                c2++;
            }if(mygraph[k]==3){
                c3++;
            }
        }
        cout<<c1<<' '<<c2<<' '<<c3<<endl;*/

}
