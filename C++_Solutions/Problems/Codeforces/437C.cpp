/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

const int INF = 1e9+1;
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

template <class T> void deb_array(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    } cout << '\n';
}

const int maxn = 1e5 + 5;
struct pp {
    long long s, a, b;
} p[maxn];
vector< pair<long long, long long> > a, b;
vector<long long> api, bpi; // stores the indexes of pizza;
vector<long long> sumbpizza, sumapizza;
long long psum, suma, sumb, box, mn;
long long ret;
int n, s;


void calc() {
    //sumb = total numbers of pizza;
    //b is {difference, pizzaseaten};
    //bpi is (sum of total number of pizza);
    if (b.size()) {
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        bpi.push_back(0);
        sumbpizza.push_back(0);
        for (int i = 0; i < b.size(); i++) {
            bpi.push_back(bpi.back() + b[i].second);
            sumbpizza.push_back(sumbpizza.back() + b[i].second * b[i].first);
        }
    }
    if (a.size()) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        api.push_back(0);
        sumapizza.push_back(0);
        for (int i = 0; i < a.size(); i++) {
            api.push_back(api.back() + a[i].second);
            sumapizza.push_back(sumapizza.back() + a[i].second * a[i].first);
        }
    }
}

long long solve(long long bbox, long long abox) {
    bbox *= s;
    abox *= s;
    long long res = 0;
    if (b.size()) {
         if (bbox > bpi.back()) {
            res += sumbpizza.back();
        } else {
            int ind = upper_bound(bpi.begin(), bpi.end(), bbox) - bpi.begin() - 1;
            res += sumbpizza[ind];
            res += (bbox - bpi[ind]) * b[ind].first;
        }
    }
    if (a.size()) {
        if (abox > api.back()) {
            res += sumapizza.back();
        } else {
            int ind = upper_bound(api.begin(), api.end(), abox) - api.begin() - 1;
            res += sumapizza[ind];
            res += (abox - api[ind]) * a[ind].first;
        }
    }
    return res;
}

int main() {

    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i].s >> p[i].a >> p[i].b;
        psum += p[i].s;
        long long d = p[i].a - p[i].b;
        if (d >= 0) {
            a.push_back({d, p[i].s});
            suma += p[i].s;
            ret += p[i].s * p[i].b;
        } else {
            b.push_back({-d, p[i].s});
            sumb += p[i].s;
            ret += p[i].s * p[i].a;
        }
    }
    box = psum / s;
    if (psum % s != 0) {
        box++;
    }
    calc();
    long long bpizza = sumb / s;
    long long apizza = box - bpizza;
    mn = solve(bpizza, apizza);
    if (bpizza + 1 <= box) {
        mn = max(mn, solve(bpizza + 1, apizza - 1));
    }
    cout << ret + mn << endl;
    return 0;
}

