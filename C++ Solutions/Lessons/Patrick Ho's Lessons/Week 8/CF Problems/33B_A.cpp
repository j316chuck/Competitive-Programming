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

string s, t;
int n;
int graph[27][27];
char convert[27][27];
int main(){

    //freopen("33B.in", "r", stdin);

    cin>>s>>t;
    cin>>n;

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            convert[i][j] = '.';
            graph[i][j] = 999;
        }
    }

    for(int i = 0; i < 26; i++){
        graph[i][i] = 0; convert[i][i] = i+97;
    }

    char a, b; int w, x, y;
    for(int i = 0; i < n; i++){
        cin>>a>>b>>w;
        x = a-'a'; y = b-'a';
        if(graph[x][y] > w){
            graph[x][y] = w;
            graph[y][x] = w;
            convert[x][y] = b;
            convert[y][x] = b;
        }
    }

    for(int k = 0; k < 26; k++){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(graph[i][j] > graph[i][k]+graph[k][j]){
                    graph[i][j] = graph[i][k]+graph[k][j];
                    convert[i][j] = convert[i][k];
                }
            }
        }
    }

    long long sum = 0;
    string result = "";
    bool negative = false;

    if(s.size()!=t.size()){
        negative = true;
    }else{
        for(int i = 0; i < s.size(); i++){
            x = s[i]-'a'; y = t[i]-'a';
            if(convert[x][y] == '.'){
                negative = true;
                break;
            }else{
                result+=convert[x][y];
                sum+=graph[x][y];
            }
        }
    }
    if(negative)
        cout<<-1<<endl;
    else
        cout<<sum<<endl<<result<<endl;
}
