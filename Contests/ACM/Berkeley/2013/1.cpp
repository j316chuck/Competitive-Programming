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
//#include <contest.h>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int main(){
    freopen("1.in", "r", stdin);
    /*string str;
    while(getline(cin, str)){
        cout<<str<<endl;
    }*/
    char words[1000];
    while(scanf("%999s", words) != EOF){
        string str(words);
        int N = atoi(str.c_str());
        int x_start, x_end, y_start, y_end, z_start, z_end;
        for(int i = 0; i < N; i++){
            int x, y, z, length;
            scanf("%d %d %d %d ", &x, &y, &z, &length);
            if(i == 0){
                x_start = x, y_start = y, z_start = z;
                x_end = x + length, y_end = y + length, z_end = z + length;
            }
            x_start = max(x_start, x);
            y_start = max(y_start, y);
            z_start = max(z_start, z);
            x_end = min(x_end, x + length);
            y_end = min(y_end, y + length);
            z_end = min(z_end, z + length);
            //cout<<x_start<<' '<<x_end<<' '<<y_start<<' '<<y_end<<' '<<z_start<<' '<<z_end<<endl;

            //printf("%d %d %d %d  \n", x, y, z, length);
        }
        //cout<<x_start<<' '<<x_end<<' '<<y_start<<' '<<y_end<<' '<<z_start<<' '<<z_end<<endl;
        //cout<<i<<endl;
        cout<<(x_end-x_start)*(y_end-y_start)*(z_end-z_start)<<endl;
    }
}
