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

int mem[1001][1001];
class friends{
public:
    string a, b;
    int number;
    bool operator < (const friends &c) const{
        if(c.a>a) return true;
        if(c.a<a) return false;
        if(c.b>b) return true;
        if(c.b<b) return false;
    }
};

class result{
public:
    string a;
    int b;
    bool operator < (const result & c)const{
        if(c.b<b) return true;
        if(c.b>b) return false;
        if(c.a<a) return true;
        if(c.a>a) return false;
    }
};

int main(){

    freopen("6.in", "r", stdin);
    //cout<<myhash("alksdjaskld");
    int N;
    string person;
    cin>>N>>person;
    vector<friends> mystrings;
    //string a, b;
    while(1){
        friends z;
        cin>>z.a>>z.b;
        if(z.a == "*" && z.b == "*")
            break;
        z.number = 0;
        mystrings.push_back(z);
    }

    /*for(int i = 0; i < mystrings.size(); i++)
        cout<<mystrings[i].first<<' '<<mystrings[i].second<<' ';*/
    sort(mystrings.begin(), mystrings.end());
    /*for(int i = 0; i < mystrings.size(); i++)
        cout<<mystrings[i].a<<' '<<mystrings[i].b<<' ';*/
    int counter = 0;
    for(int i = 0; i < mystrings.size()-1; i++){
        if(mystrings[i].a!=mystrings[i+1].a){
            counter+=1;
        }
        mystrings[i].number = counter;
    }
    vector<string> fri;
    for(int i = 0; i < mystrings.size(); i++){
        if(person == mystrings[i].a){
            fri.push_back(mystrings[i].b);
        }else if(person == mystrings[i].b){
            fri.push_back(mystrings[i].a);
        }
    }
    /*for(int i=0 ; i < fri.size(); i++){
        cout<<fri[i]<<' ';
    }*/
    vector<string> friendof;
    for(int i = 0; i < mystrings.size(); i++){
        for(int j = 0; j < fri.size(); j++){
            if(mystrings[i].a == fri[j] &&mystrings[i].a != person){
                friendof.push_back(mystrings[i].b);
                break;
            }if(mystrings[i].b == fri[j] && mystrings[i].a != person){
                friendof.push_back(mystrings[i].a);
                break;
            }
        }
    }
    sort(friendof.begin(), friendof.end());
    vector< result > res;
    counter = 1;
    for(int i = 0; i < friendof.size()-1; i++){
        if(friendof[i]==friendof[i+1])
            counter++;
        else{
            result c;
            c.a = friendof[i];
            c.b = counter;
            res.push_back(c);
            counter = 1;
        }
    }
    sort(res.begin(), res.end());

    /*for(int i = 0; i < res.size(); i++){
        cout<<res[i].a<<' '<<res[i].b<<' ';
    }*/
    for(int i = 0; i < N; i++)
        cout<<res[i].a<<' ';
    cout<<endl;
    //printf("%d %d ", &mystrings[i].first, &mystrings[i].second);

}
