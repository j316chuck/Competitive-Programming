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
int length1;
int mem[1000][1000];

/*void Recurse(string n, string m, int length){
    if(n.size()==0||m.size()==0){
        length1=max(length1, length);
        //cout<<length1<<' '<<n<<' '<<m<<endl;
        return;
    }
    if(n[n.size()-1]==m[m.size()-1]){
        Recurse(n.substr(0, n.size()-1), m.substr(0, m.size()-1), length+1);

    }else{
        Recurse(n.substr(0, n.size()-1), m, length);
        Recurse(n, m.substr(0, m.size()-1), length);
    }
}*/
int N, M;
string B;
int Recurse(string n, string m, string b){
    if(n.size()==0||m.size()==0){
        //length1=max(length1, length);
        //cout<<length1<<' '<<n<<' '<<m<<endl;
        return 0;
    }if(mem[n.size()][m.size()]!=-1){
        return mem[n.size()][m.size()];
    }if(n[n.size()-1]==m[m.size()-1]){
        mem[n.size()][m.size()]=Recurse(n.substr(0, n.size()-1), m.substr(0, m.size()-1), b+n[n.size()])+1;
        //cout<<b<<endl;
        return mem[n.size()][m.size()];
    }else{
        mem[n.size()][m.size()]=max(Recurse(n.substr(0, n.size()-1), m, b),Recurse(n, m.substr(0, m.size()-1),b));
        //cout<<b<<endl;
        return mem[n.size()][m.size()];
    }
}

int main(){
    memset(mem, -1, sizeof(mem));
    string n, m;
    cin>>n>>m;
    N=n.size();
    M=m.size();
    cout<<Recurse(n, m, "");
    //cout<<B<<endl;
    //cout<<length1;
    //cout<<n.size();

}
