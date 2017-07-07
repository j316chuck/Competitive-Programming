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

template <class T> void deb_array(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    } cout << '\n';
}

//calculate prime factor in O(log n)
//basic idea is calculate sieve and record the first prime
//then use while loop to keep on recording the least prime of n
const int maxn = 1e7 + 1;
bool prime[maxn];
int divisor[maxn];
void sieve() {
    for(int i = 2; i < maxn; i++) {
        prime[i] = true;
    }
    for(int i = 2; i< maxn; i++) {
        if(prime[i]) {
            divisor[i] = i;
            for(int j = 2; i * j < maxn; j++) {
                prime[i*j] = false;
                if(divisor[i*j] == 0) {
                    divisor[i*j] = i;
                }
            }
        }
    }
}

//factorizes n in O(1) after calculating the sieve
int prime_factorize(int n, vector<int> &divisors) {
    while(n != 1) {
        divisors.push_back(divisor[n]);
        n /= divisor[n];
    }
    /*for (int j = n; j > 1; j /= divisor[j]) {
            fn[divisor[j]]++;
            divisors.push_back(divisor[j]);
    } */
}

int fm[maxn];
int fn[maxn];
int main() {

    //time_t start=clock();
    //Rd("222C.in");
    ios_base::sync_with_stdio(0);
    sieve();
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m], b[n];
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        for (int j = a[i]; j > 1; j /= divisor[j]) {
            fm[divisor[j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        for (int j = b[i]; j > 1; j /= divisor[j]) {
            fn[divisor[j]]++;
        }
    }
    printf("%d %d\n", m, n);
    for (int i = 0; i < m; i++) {
        int res = 1;
        for (int j = a[i]; j > 1; j /= divisor[j]) {
            if (fn[divisor[j]]) {
                fn[divisor[j]]--;
            } else {
                res *= divisor[j];
            }
        }
        printf("%d ", res);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        int res = 1;
        for (int j = b[i]; j > 1; j /= divisor[j]) {
            if (fm[divisor[j]]) {
                fm[divisor[j]]--;
            } else {
                res *= divisor[j];
            }
        }
        printf("%d ", res);
    }
    printf("\n");
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




