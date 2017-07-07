#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'
using namespace std;

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
const double PI = acos(-1.0);

int main() {
    Rd("sight.in");
    Wt("sight.out");
    int n; double r;
    scanf("%d %lf", &n, &r);
    vector< pair<double, double> > angs;
    double x, y;
    double theta, alpha;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        alpha = acos(r/sqrt(x * x * 1.0 + y * y * 1.0));
        theta =  atan2(y, x) - alpha;
        if (theta < 0) theta += 2 * PI;
        angs.push_back(make_pair(theta, theta + 2 * alpha));
    }
    sort(angs.begin(), angs.end());

    set<double> st;
    long long total = 0;
    for (int iteration = 0; iteration < 2; iteration++) {
        for (int i = 0; i < n; i++) {
            //deb(st);
            while (st.size() && *st.begin() < angs[i].first) {
                st.erase(st.begin());
            }
            if (iteration == 1) total += st.size();
            st.insert(angs[i].second);
            angs[i].first += 2*PI;
            angs[i].second += 2*PI;
        }
    }
    printf("%lld\n", total);

}
