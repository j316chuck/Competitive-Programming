/*
ID: j316chuck
PROG: fracdec
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

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

void output(string answer){
    if(answer.length()> 76){
        for(int i = 0; i < answer.size(); i+=76){
            cout<<answer.substr(i, 76)<<endl;
        }
    }else{
        cout<<answer<<endl;
    }
}

int main(){
    Rd("fracdec.in");
    Wt("fracdec.out");

    int N, d;
    cin>>N>>d;
    int R[d];
    int n = N%d;
    int r = n%d;
    memset(R, -1, sizeof(R));
    bool cont = true;
    R[r] = 0;
    string fraction = "";
    while(cont){
        fraction+=convertInt(r*10/d);
        r = (r*10)%d;
        if(r == 0){
            output(convertInt(N/d)+"."+fraction);
            return 0;
        }
        if(R[r]!=-1){
            cont = false;
        }else{
            R[r] = fraction.length();
        }
    }
    fraction = fraction.substr(0, R[r])+'('+fraction.substr(R[r], fraction.length()) + ')';
    if(fraction.substr(fraction.length()-3, 3) == "(0)")
        fraction = fraction.substr(0, fraction.length()-3);
    output(convertInt(N/d) + "." + fraction);
}
