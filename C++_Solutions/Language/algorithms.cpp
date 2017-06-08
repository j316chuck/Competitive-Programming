/*
ID: j316chuck
PROG: algorithms
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
    cout << "DEBUG: {";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    } cout << "}\n";
}

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject; //defines my object

int main() {
    //count is O(n) find is O(n) don't use
    //random_shuffle (generate random sequence)
    //set operations set_union (can be used in vectors, vectors must be sorted)
    //linear in cost; set_difference, set_intersection

    //push_heap
    //pop_heap make_heap (can use vector as heap but basically just use priority queue
    int myints[] = {32,71,12,45,26,80,53,33};
    vector<int> myvector (myints, myints+8);
    sort(myvector.begin(), myvector.begin() + 4);
    sort(myvector.begin() + 4, myvector.end(), myfunction);
    deb(myvector);

    sort(myvector.begin(), myvector.end(), myobject);
    deb(myvector);
    rotate(myvector.begin(), myvector.begin() + 1, myvector.end() - 1);
    rotate(myints, myints + 1, myints + sizeof(myints)/sizeof(int));
    deb(myvector);
    deb_array(myints, sizeof(myints)/sizeof(int)); //cool nice!
    reverse(myvector.begin(), myvector.end());
    deb(myvector);
    auto odd = [&](int i) { return i % 2 == 1;}; //true and false;
    vector<int>::iterator bound = partition(myvector.begin(), myvector.end(), odd);
    for (auto it = myvector.begin(); it != bound; ++it) {
        cout << *it <<' ';
    } cout <<endl;
    for (auto it = bound; it != myvector.end(); ++it) {
        cout << *it << ' ';
    } cout << endl;
    sort(myvector.begin(), myvector.end());
    //binarysearch  = found or not found
    //lower_bound = >= upper_bound = >
    int low = lower_bound(myvector.begin(), myvector.end(), 71) - myvector.begin();
    cout << low << endl;
    cout << myvector[low] << endl;
    int high = upper_bound(myvector.begin(), myvector.end(), 71) - myvector.begin();
    cout << myvector[high] << endl;

    //next_permutation
    do {
        std::cout << myvector[0] << ' ' << myvector[1] << ' ' << myvector[2] << '\n';
    } while ( next_permutation(myvector.begin(),myvector.begin() + 3) );


}

