/*
ID: j316chuck
PROG: sets
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = pow(10, -5);
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

class pp{
public:
    int u, v;
    pp(int uu, int vv);
    bool operator < (const pp & a) const { //make sure to put const which means you can't modify other variables...
        if (a.u < u) return true;
        else if(a.u > u) return false;
        return a.v > v;
    }
};

pp::pp(int uu, int vv) {
    u = uu;
    v = vv;
}

ostream &operator << (ostream & os , const pp &x) {
    os << "(" << x.u << ", " << x.v << ")";
    return os;
}

//can also implement a struct... easiest way = just do the bool operator...
bool cmp(pp a, pp b) {
    if (a.u < b.u) return true;
    else if(a.u > b.u) return false;
    return a.v > b.v;
}


int main() {
    //binarysearch tree = O(nlogn)
    //useful for inserting and erasing and finding and counting...
    //time_t start=clock();
    Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);

    set<pp> st;
    st.insert(pp(3, 4));
    for (auto it = st.begin() ; it != st.end(); it++) {
        cout << *it << endl;
    }
    cout << st.empty() << ' ' << st.size() << endl;
    st.insert(pp(4, 5));
    st.insert(pp(4, 6));
    st.insert(pp(6, 7));
    for (auto it = st.begin() ; it != st.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    set<pp, bool(*)(pp, pp)> sts(cmp);
    sts.insert(pp(3, 4));
    sts.insert(pp(4, 5));
    sts.insert(pp(4, 6));
    sts.insert(pp(6, 7));
    for (auto it = sts.begin() ; it != sts.end(); it++) {
        cout << *it << endl;
    }
    //Two elements of a set are considered equivalent
    //if key_comp returns false reflexively
    //(i.e., no matter the order in which the elements are passed as arguments).

    sts.erase(pp(6, 7));
    for (auto it = sts.begin() ; it != sts.end(); it++) {
        cout << *it << endl;
    }
    sts.erase(sts.find(pp(3, 4)));
    for (auto it = sts.begin() ; it != sts.end(); it++) {
        cout << *it << endl;
    } cout << endl; //returns sts.end() if it is not found
    if (sts.find(pp(1, 0))!=sts.end()) sts.erase(sts.find(pp(1, 0)));
    cout << sts.count(pp(3, 4)) << endl;

    //Notice that lower_bound(30) returns an iterator to 30, whereas upper_bound(60) returns an iterator to 70.
    //lower_bound = >=
    //upper_bound = >
    set<int> myset;
    //for (int i = 0; i < 10; i++) myset.insert(i);
    myset = {1,2,3,4,5,6,7,8,9};
    cout << *myset.lower_bound(5) <<endl;
    auto itr = myset.upper_bound(6);
    myset.erase(itr, myset.end());
    for (auto it = myset.begin() ; it != myset.end(); it++) {
        cout << *it << endl;
    }

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



