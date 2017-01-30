/*
ID: j316chuck
PROG: hamming
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


int length(int a){
    int count=0;
    while(a!=0){
        if(a%2==1)
            count++;
        a=a/2;
    }
    return count;
}
vector< vector<int> > mygraph;
//vector<int> goal;
//int mygraph[256];
int N, B, D;
//vector<int> result;

/*void Recurse(int counter, int position, int terminate){
    if(terminate==1){
        return;
    }
    if(counter==B){
        terminate=1;
        for(int i=0; i<result.size(); i++){
            cout<<result[i]<<' ';
        }
        return;
    }
    result.push_back(position);
    mygraph[position]=1;
    for(int i=0; i<pow(2,B); i++){
        if(mydiff[position][i]<D){
            mygraph[i]=1;
        }
    }
    for(int i=0; i<pow(2,B); i++){
        if(mygraph[i]!=1){
            Recurse(counter+1, i,terminate);
        }
    }
    mygraph[position]=0;
    for(int i=0; i<pow(2,B); i++){
        if(mydiff[position][i]<D){
            mygraph[i]=0;
        }
    }
    result.pop_back();
}*/vector<int> success;
int main()
{
    Rd("hamming.in");
    Wt("hamming.out");
    cin>>N>>B>>D;
    success.push_back(0);
    for(int i=0; i <pow(2,B); i++){
        vector<int> random;
        for(int k=0; k<pow(2,B); k++){
            int b=i^k;
            int a=length(b);
            random.push_back(a);
        }
        mygraph.push_back(random);
    }
    for(int i=0; i<1<<B; i++){
        for(int j=0; j<success.size(); j++){
            if(mygraph[success[j]][i]<D){
                break;
            }if(j==success.size()-1){
                success.push_back(i);
            }
        }
        if(success.size()==N){
            break;
        }
    }
    for(int i=0; i<success.size(); i++){
        if(i==success.size()-1){
            cout<<success[i]<<'\n';
        }else if(i%10!=9)
            cout<<success[i]<<' ';
        else
            cout<<success[i]<<'\n';
    }
}
