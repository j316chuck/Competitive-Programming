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

int main(){
    Rd("names.txt");
    string s;
    cin>>s;
    istringstream ss(s);
    string token;
    vector<string> mystrings;
    while(getline(ss, token, ',')){
        mystrings.push_back(token);
        //cout<<token<<'\n';
    }
    int answer=0;
    sort(mystrings.begin(), mystrings.end());
    for(int i=0; i<mystrings.size(); i++){
        string s=mystrings[i];
        int sum=0;
        for(int k=0; k<s.size(); k++){
            if(s[k]=='"'){
                continue;
            }else{
                sum+=(s[k]-'0'-16);
            }
        }
        answer+=(sum*(i+1));
        //cout<<mystrings[i]<<endl;
    }
    cout<<answer<<endl;
}
