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

using namespace std;

string floyd(double graph[][35], int n){

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j <= n; j++){
                //if(graph[i][k]!=-1 && graph[k][j]!=-1)
                graph[i][j] = max(graph[i][j], graph[i][k]*graph[k][j]);
            }
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }*/
    for(int i = 1; i <= n; i++)
        if(graph[i][i]>1.0)
            return "Yes";

    return "No";
}

int main(){

    //freopen("poj_2240.in", "r", stdin);

    int n, m, counter = 0;

    while(cin>>n && n!=0){

        map<string, int> strings; strings.clear();

        double graph[35][35];
        for(int i = 0; i <= 30; i++){
            for(int j = 0; j <= 30; j++){
                graph[i][j] = 0;
            }
        }
        for(int i = 1; i <= 30; i++)
            graph[i][i] = 1;

        for(int i = 1; i <= n; i++){
            string s;
            cin>>s;
            //cout<<s<<' '<<i<<endl;
            strings[s] = i;
        }

        /*map<string, int>::iterator itr;
        for(itr = strings.begin(); itr!=strings.end(); itr++){
            cout<<itr->first<<' '<<itr->second<<endl;
        }*/

        cin>>m;

        for(int i = 1; i <= m; i++){
            string s1, s2; double v;
            cin>>s1>>v>>s2;
            //cout<<s1<<' '<<s2<<endl;
            //cout<<strings[s1]<<' '<<strings[s2]<<endl;
            graph[strings[s1]][strings[s2]] = v;
        }

        /*for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                cout<<graph[i][j]<<' ';
            }cout<<endl;
        }*/

        //cout<<floyd(graph, n)<<endl;
        string res = floyd(graph, n);
        //cout<<res<<endl;

        printf("Case %d: %s\n", ++counter, res.c_str());

    }

    return 0;

}
