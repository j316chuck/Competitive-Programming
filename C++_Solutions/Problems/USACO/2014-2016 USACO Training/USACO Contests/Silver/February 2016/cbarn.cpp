
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

vector< vector< pair<int, int> > > myvector;

int main(){
    Rd("cbarn.in");
    Wt("cbarn.out");
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        vector < pair<int, int> > r;
        if(a>0){
            for(int k=0; k<a; k++){
                pair<int, int> rand;
                rand.first=1;
                rand.second=0;
                r.push_back(rand);
            }
        }
        else if(a==0){
            pair<int, int> rand;
            rand.first=0;
            rand.second=0;
            r.push_back(rand);
        }
        myvector.push_back(r);
    }
    int num=0;

    while(num!=N){
        num=0;
        for(int i=0; i<N; i++){
            if(myvector[i][0].first==1){
                num++;
            }if(myvector[i].size()>1){
                int maximum=myvector[i][0].second;
                int place=0;
                vector< pair<int, int> > temp;
                for(int k=0; k<myvector[i].size(); k++){
                    if(myvector[i][k].second>maximum){
                        maximum=myvector[i][k].second;
                        place=k;
                    }
                }
                for(int k=0; k<myvector[i].size(); k++){
                    if(k!=place){
                        myvector[i][k].second++;
                        temp.push_back(myvector[i][k]);
                    }
                }
                myvector[i].clear();
                pair<int, int> randomizer; randomizer.first=1; randomizer.second=maximum;
                myvector[i].push_back(randomizer);

                if(i==N-1){
                    if(myvector[0][0].first==0){
                        myvector[0].clear();
                    }
                    for(int k=0; k<temp.size(); k++){
                        myvector[0].push_back(temp[k]);
                    }
                }else{
                    if(myvector[i+1][0].first==0){
                        myvector[i+1].clear();
                    }
                    for(int k=0; k<temp.size(); k++){
                        myvector[i+1].push_back(temp[k]);
                    }
                }
            }
            /*for(int k=0; k<N; k++){
                cout<<k<<' ';
                for(int j=0; j<myvector[k].size(); j++){
                    cout<<myvector[k][j].first<<' '<<myvector[k][j].second*myvector[k][j].second<<' ';
                }cout<<endl;

            }*/
        }
    }
    int sum=0;
    for(int i=0; i<N; i++){
        sum+=myvector[i][0].second*myvector[i][0].second;
    }
    cout<<sum<<endl;
}
