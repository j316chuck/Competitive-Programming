/*
ID: j316chuck
PROG: sort3
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

vector<int> mygraph;
int main()
{
    Rd("sort3.in");
    Wt("sort3.out");
    int N;
    cin>>N;
    int one=0, two=0, three=0;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        if(a==1)
            one++;
        if(a==2)
            two++;
        if(a==3)
            three++;
        mygraph.push_back(a);
    }
    int counter=0;
    for(int i=0; i<one; i++){
        if(mygraph[i]==2){
            for(int k=one; k<N; k++){
                if(mygraph[k]==1){
                    mygraph[i]=1;
                    mygraph[k]=2;
                    counter++;
                    break;
                }
            }
        }if(mygraph[i]==3){
            for(int k=N-1; k>=one; k--){
                if(mygraph[k]==1){
                    mygraph[i]=1;
                    mygraph[k]=3;
                    counter++;
                    break;
                }
            }
        }
    }
    //cout<<counter<<endl;
    /*string s;
    for(int i=0; i<one; i++){
        s+='1';
    }for(int i=0; i<two; i++){
        s+='2';
    }for(int i=0; i<three; i++){
        s+='3';
    }
    string a;
    for(int i=0; i<mygaph.size(); i++){
        a+=mygraph[k]+'0';
    }*/
    //cout<<one<<two<<three<<endl;
    /*for(int i=0; i<mygraph.size(); i++){
        cout<<mygraph[i];
    }cout<<endl;*/
    vector<int> correct;
    for(int i=0; i<one; i++){
        correct.push_back(1);
    }for(int i=0; i<two; i++){
        correct.push_back(2);
    }for(int i=0; i<three; i++){
        correct.push_back(3);
    }
    int moves=0;
    for(int i=one; i<correct.size(); i++){
        if(correct[i]!=mygraph[i]){
            moves++;
        }
    }
    cout<<counter+moves/2<<endl;
}

