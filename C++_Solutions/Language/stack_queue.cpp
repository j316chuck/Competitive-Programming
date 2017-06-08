/*
ID: j316chuck
PROG: stack & queue
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

int main() {

    //time_t start=clock();
    Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    /*Construct queue (public member function )
    empty
    Test whether container is empty (public member function )size
    Return size (public member function )
    front
    Access next element (public member function )
    back
    Access last element (public member function )
    push
    Insert element (public member function )
    emplace
    Construct and insert element (public member function )
    pop
    Remove next element (public member function )
    swap
    Swap contents (public member function ) */
    queue<int> q;
    q.push(6); q.push(5);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;

    //can implement vector as a stack
    vector<int> stk;
    stk.push_back(1);
    stk.push_back(2);
    stk.push_back(3);
    cout << stk.back() << endl;
    stk.pop_back();

    //or same deal as queue
    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    st.pop();
    cout << st.top() <<endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



