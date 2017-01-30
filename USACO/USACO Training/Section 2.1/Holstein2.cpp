/*
ID: j316chuck
PROG: holstein
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int V, G;
vector<int> goal;
vector< vector<int> > mygraph;
vector<int> current;
vector<int> result;
int moves=9999;
vector<int> success;
bool check(vector<int> &curre){
    for(int i=0; i<curre.size(); i++){
        if(curre[i]-goal[i]<0)
            return false;
    }
    return true;
}
void Recurse(int position, int counter, vector<int> &curr){
    for(int k=0; k<curr.size(); k++){
        curr[k]+=mygraph[position][k];
    }
    result.push_back(position);
    if(check(curr)==true){
        //cout<<counter<<endl;
         for(int k=0; k<curr.size(); k++){
            curr[k]-=mygraph[position][k];
         }
         if(moves>counter){
            moves=counter;
            success.erase(success.begin(), success.end());
            for(int i=0; i<result.size(); i++){
                success.push_back(result[i]);
            }
         }
         if(moves==counter){
            for(int i=0; i<result.size(); i++){
                if(result[i]<success[i]){
                    success.erase(success.begin(), success.end());
                    for(int k=0; k<result.size(); k++){
                        success.push_back(result[k]);
                    }
                }else if(result[i]>success[i]){
                    break;
                }else{
                    continue;
                }
            }
         }
         /*for(int i=0; i <result.size(); i++){
            cout<<result[i]<<' ';
         }
         cout<<endl;*/
         result.pop_back();
        return;
    }
    for(int i=position+1; i<G; i++){
        Recurse(i, counter+1, curr);
    }
    result.pop_back();
    for(int k=0; k<curr.size(); k++){
        curr[k]-=mygraph[position][k];
    }
}
int main()
{
    Rd("holstein.in");
    Wt("holstein.out");
    cin>>V;
    for(int i=0; i<V; i++){
        int a;
        cin>>a;
        goal.push_back(a);
        current.push_back(0);
    }
    cin>>G;
    for(int i=0; i<G; i++){
        vector<int> random;
        for(int k=0; k<V; k++){
            int a;
            cin>>a;
            random.push_back(a);
        }
        mygraph.push_back(random);
    }
    for(int i=0; i<G; i++){
        Recurse(i,1, current);
    }
    cout<<moves<<' ';
    for(int i=0; i<success.size(); i++){
        if(i!=success.size()-1)
            cout<<success[i]+1<<' ';
        else
            cout<<success[i]+1<<endl;
    }

    return 0;
}
