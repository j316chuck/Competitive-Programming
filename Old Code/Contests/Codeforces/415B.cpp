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

class pp{
public:
    long long k, l;
    bool operator < (const pp &a) const {
        return min(2 * k , l) - k > min(2 * a.k, a.l) - a.k;
    }
};

int main(){

    //Rd("input.in");
    int n; long long f;
    scanf("%d %I64d", &n, &f);
    vector<pp> customers;
    for (int i = 0; i < n; i++) {
        pp ei;
        scanf("%I64d %I64d", &ei.k, &ei.l);
        customers.push_back(ei);
    }
    sort(customers.begin(), customers.end());
    /*for (int i = 0; i < customers.size(); i++) {
        cout<< customers[i].k <<' '<< customers[i].l<< endl;
    }*/
    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (i < f) {
            total += min(2 * customers[i].k, customers[i].l);
        } else {
            total += min(customers[i].k, customers[i].l);
        }
    }
    printf("%I64d\n", total);


}

