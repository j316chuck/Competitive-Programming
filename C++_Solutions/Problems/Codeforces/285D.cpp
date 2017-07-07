#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> st;
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
typedef long long LL;
using namespace std;

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

const int maxn = 2e5+5;
int bit[maxn];

void update(int x, int val) {
    for (; x < maxn; x += x & -x) {
        bit[x] += val;
    }
}
int sum(int x) {
    int total = 0;
    for (; x > 0; x -= x & -x) {
        total += bit[x];
    }
    return total;
}

int main() {
    //freopen("285D.in", "r", stdin);
    int n, x;
    scanf("%d", &n);
    vector<int> s1, s2;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s1.push_back(x - sum(x+1));
        update(x+1, 1);
    }
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s2.push_back(x - sum(x+1));
        update(x+1, 1);
    }
    deb(s2);
    vector<int> ret(n);
    int mod = 1;
    for (int i = n-1; i >= 1; i--) {
        ret[i] += s1[i] + s2[i];
        ret[i-1] += ret[i] / (n-i);
        ret[i] %= (n-i);
    }
    ret[0] += s1[0] + s2[0];
    ret[0] %= n;
    deb(ret);
    for (int i = 0; i < n; i++) {
        st.insert(i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", *st.find_by_order(ret[i]));
        st.erase(st.find_by_order(ret[i]));
    }
    printf("\n");
}
