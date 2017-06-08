/*
ID: j316chuck
PROG: deque & pq
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

struct compare {
    bool operator() (const int &l, const int &r) {
        return l < r;
    }
};

int main() {

    //time_t start=clock();
    Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    //deques are similar to vectors but have better insert front and insert back operations
    //not good for lots of inserts and deletions use insert + deletion sparingly O(1);
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    dq.pop_back();
    for (auto it = dq.begin(); it != dq.end(); it++) cout << *it <<endl;

    //priority_queue's are heaps that can run in O(nlogn);
    //max heaps such that only the greatest element can be retrieved
    //implemented with underlying container with Random access iterator or vector
    //uses Compare a binary predicate to make strict weak ordering

    //top push pop size empty
    //implement pp to make it easier
    //or you can use something like this
    //priority_queue<int, vector<int>, greater<int> > min_heap;
    priority_queue<int, vector<int>, compare> min_heap;
    min_heap.push(3); min_heap.push(4); min_heap.push(5);
    while(!min_heap.empty()) {
       cout << min_heap.top() <<endl;
       min_heap.pop();
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}


