/*
ID: j316chuck
PROG: iterators;
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double Pi= acos(-1.0);
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

/*
Advance iterator (function template )
distance
Return distance between iterators (function template)
begin
Iterator to beginning (function template )
end
Iterator to end (function template )
prev
Get iterator to previous element (function template)
next
Get iterator to next element (function template)
*/

//random access iterators
//http://en.cppreference.com/w/cpp/concept/RandomAccessIterator
//allows [] and a+n
//vectors
//allows iterator/pointer + k;
// < and > etc.

//bidirectional iterators
//sets can only do so by doing advance etc. maps too
//still can iterate through map etc.

int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //(*i).first == i -> first;
    //syntax
    //std::class_name<template_parameters>::iterator name
    vector<int>::iterator itr;
    vector<int> vec; vec.push_back(1); vec.push_back(2);
    for (itr = vec.begin(); itr != vec.end(); itr++) {
        cout << (*itr) << ' ';
    } cout << endl;
    for (auto itr : vec) {
        cout << (itr) << ' ';
    }

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



