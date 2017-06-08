/*
ID: j316chuck
PROG: vector
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

vector<int>* hello() { //instead you can do this...
    vector<int> *v = new vector<int>;
    for (int i = 0; i < 10; i++) {
        v -> push_back(i);
    }
    return v;
}

/*vector<int> & hello() {
    vector<int> v; //doesn't work because dangling pointer //v is only defined in place...;
    return v;
}*/

int main() {

    //time_t start=clock();
    Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    vector<int> v (10, 0);
    vector<int> v_copy(v);
    deb(v_copy);
    vector<int> v_range(v.begin(), v.begin() + 5);
    deb(v_range);
    int myints[] = {16, 2, 77, 29};
    vector<int> v_array_copy(myints, myints + sizeof(myints)/sizeof(int));
    deb(v_array_copy);

    // = operator copies every element ... O(N) cost
    //call function foo(vector<int> x) foo(v); x = v; assignment in function;
    vector<int> foo(3, 0);
    vector<int> bar(5, 0);
    vector<int> &temp = bar; //bar is now = to foo no matter what (does it in O(1))
    vector<int> *tmp = &bar; //*tmp = now bar no matter what (does it in O(1) similar to Java pointer)
    bar = foo;
    bar.erase(bar.end() - 1);
    deb(foo); deb(temp); deb(bar); deb(*tmp);
    cout << foo.size() << ' ' << bar.size() << endl;
    foo = vector<int> ();
    cout << foo.size() << ' ' << bar.size() << endl;

    vector<int> myvector(5);
    int i = 0;
    vector<int>::reverse_iterator rit = myvector.rbegin(); //reverse iterator
    for (; rit != myvector.rend(); ++rit) {
        *rit = ++i;
    }
    deb(myvector);
    cout << myvector.empty() << ' ' << myvector.size() << endl;
    cout << myvector.front() << ' ' << myvector.back()  << ' ' << myvector[2] << ' ' << myvector.at(0) <<endl;
    //try to use vector for everything... arrays suck...
    //assignment operators
    myvector.pop_back(); //can use like a stack vector is very similar to a stack...
    myvector.push_back(1);
    auto it = myvector.insert(myvector.begin(), 2, 300); //how many and what
    deb(myvector);
    vector<int> v2 (2, 400);
    myvector.insert(it + 2, v2.begin(), v2.end());
    deb(myvector);
    //myvector.clear();

    //erase = based on iterator
    sort(myvector.begin(), myvector.end());
    //it = find(myvector.begin(), myvector.end(), 1);
    //cout << *it << endl;
    //myvector.erase(it);
    //deb(myvector);
    //int maxi = *max_element(myvector.begin(), myvector.end());
    //cout << maxi << endl;
    //algorithms
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    //cout << "Hi" <<endl;
    int n = 10, m = 5;
    vector< vector<int> > matrix(n, vector<int> (m, -1));
    vector<int> *c = hello();
    deb(*c);
    delete c;

    //vector<int> &c = hello();
    //deb(c);
    //pass in const = vector<int>::const_iterator it = v.begin(); it != v.end();

    return 0;
}



