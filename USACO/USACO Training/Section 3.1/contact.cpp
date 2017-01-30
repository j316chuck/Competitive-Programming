/*ID: j316chuck
PROG: contact
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
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;

int mem[10001];

string bit(int num){

    string str = "";
    while(num!=0){
        str += (num % 2 == 0 ? '1' : '0');
        num = (num - 1)/2;
    }
    reverse(str.begin(), str.end());
    return str;
}

class pp{
public:
    int counter;
    int bit;
    string str;

    bool operator < (const pp & a) const{
        return counter > a.counter || (counter == a.counter && bit < a.bit);
    }

};

int main(){

    Rd("contact.in");
    Wt("contact.out");

    int A, B, N;
    cin>>A>>B>>N;
    string S;
    string s;
    while(cin>>s){
        S+=s;
    }

    for(int i = 0; i < S.size(); i++){
        int sum = 0;
        for(int len = 1; len <= 12 && len + i <= S.size(); len++){
             sum = 2 * sum + 1 + (S[i+len-1]-'0');
             mem[sum]++;
        }
    }

    vector<pp> G;
    for(int i = pow(2, A) - 1; i < pow(2, B+1) - 1; i++){
        pp ei;
        ei.bit = i;
        ei.counter = mem[i];
        ei.str = bit(i);
        if(ei.counter!=0)
            G.push_back(ei);
    }

    sort(G.begin(), G.end());

    int i = 0, length = 1;
    while(length <= N && i < G.size()){
        vector<string> out;
        out.clear();
        out.push_back(G[i].str);
        while(i+1 < G.size()){
            if(G[i].counter == G[i+1].counter){
                i++;
                out.push_back(G[i].str);
            }else{
                break;
            }
        }
        cout<<G[i].counter<<endl;
        for(int k = 0; k < out.size(); k++){
            if(k % 6 == 5 || k == out.size()-1){
                cout<<out[k]<<endl;
            }else{
                cout<<out[k]<<' ';
            }
        }
        length++;
        i++;
    }

    return 0;
}


