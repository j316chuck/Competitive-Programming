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

vector<int> myarray;
int mem[1000];

int N;

int Recurse(int k){
    if(k==N-1){
        return 1;
    }if(mem[k]!=-1){
        return mem[k];
    }for(int i=k+1; i<N; i++){
        if(myarray[k]<myarray[i]){
            mem[k]=max(Recurse(i)+1, mem[k]);
        }
        if(i==N-1&&mem[k]!=-1){
            cout<<k<<' '<<mem[k]<<endl;
            return mem[k];
        }
    }
    return 1;
}
int main(){
    Rd("LIS.txt");
    memset(mem,-1, sizeof(mem));
    cin>>N;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        myarray.push_back(k);
    }
    int array[1000];
    mem[N-1]=1;
    for(int i=0; i<N; i++){
        array[i]=Recurse(i);
        //cout<<array[i];
    }
    sort(array, array+N);
    for(int i=0; i<N; i++){
        cout<<array[i]<<endl;
    }

    //sort(array, array+N);
    //cout<<array[0]<<endl;

    //bottom down
    /*mem[myarray.size()-1]=1;
    for(int i=N-2; i>=0; i--){
        for(int k=i+1; k<=N-1; k++){
            if(myarray[i]<myarray[k]){
                mem[i]=max(mem[i], mem[k]+1);
            }if(mem[i]==-1&&k==N-1){
                mem[i]=1;
            }
        }
    }

   //sort(mem, mem+1000);
    for(int i=0; i<N; i++){
        cout<<mem[i]<<endl;
    }*/
    //cout<<"Alex is gay"<<endl;
}
