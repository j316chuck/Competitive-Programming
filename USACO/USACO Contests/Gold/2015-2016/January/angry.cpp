/*ID: j316chuck
PROG: angry
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

using namespace std;

int main(){

    freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> graph;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        graph.push_back(a);
    }
    sort(graph.begin(), graph.end());

    vector<int> left;
    left.push_back(0);
    left.push_back(graph[graph.size()-1]-graph[graph.size()-2]);
    for(int i = graph.size()-3; i>=0; i--){
        int minimum = INT_MAX;
        for(int j = i+1; j < graph.size() && j < 1000; j++){
            int value = max(graph[j]-graph[i], left[graph.size()-j-1]+1);
            minimum = min(minimum, value);
        }
        left.push_back(minimum);
    }
    /*for(int i = 0; i < left.size(); i++){
        cout<<left[i]<<endl;
    }*/
    vector<int> right;
    right.push_back(0);
    right.push_back(graph[1]-graph[0]);
    for(int i = 2; i < graph.size(); i++){
        int minimum = INT_MAX;
        for(int j = i-1; j>=0 && j >= i-1000; j--){
            int value = max(graph[i]-graph[j], right[j]+1);
            minimum = min(minimum, value);
        }
        right.push_back(minimum);
    }
    double res = min(right[n-1], left[n-1]);
    right.pop_back();
    left.pop_back();
    reverse(left.begin(), left.end());
    /*for(int i = 0; i < left.size(); i++){
        cout<<right[i]<<' '<<left[i]<<endl;
    }*/
    for(int i = 1; i < graph.size()-1; i++){
        double minimum = INT_MAX;
        double one = right[i-1];
        double two = left[i-1];
        //cout<<one<<' '<<two<<endl;
        double value = graph[i]-graph[i-1];
        if(one!=two){
            minimum = max(one, two);
            if(minimum >= value){
                res = min(res, minimum);
            }else{
                res = min(res, max(minimum+1, value/2.0));
            }
        }else{
            if(value/2 < two+1){
                res = min(res, two+1);
            }else{
                res = min(res, value/2);
            }
        }
        //cout<<res<<endl;
    }
    //cout<<res<<endl;
    printf("%.1f\n", res);
    /*for(int i = 0; i < right.size(); i++){
        cout<<right[i]<<endl;
    }*/

}
