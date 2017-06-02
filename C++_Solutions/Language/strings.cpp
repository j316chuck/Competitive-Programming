/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#include <string>
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



int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //strings are char arrays
    //'\0' == null character

    char helloworld[] = "hello world!";
    for (int i = 0; helloworld[i]; i++) {
        if (isalpha(helloworld[i])) {
            cout << (char) (isupper(helloworld[i]) ? tolower(helloworld[i]) : helloworld[i]);
        }
    }

    //string to int;
    string s = "2001";
    int value = atoi(s.c_str());
    printf("%d\n", value);

    //slower way
    string myStream = "45";
    istringstream buffer(s);
    buffer >> value;
    cout << value << endl;

    //int to string
    //s = to_string(value); //codeblocks is being dumb I need to reinstall
    cout << s << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    int a = 10;
    stringstream ss; ss << a;
    string str = ss.str();
    cout << str << endl;
    // slower way
    /*char *intStr = itoa(a); codeblocks being dumb
    str = string(intStr);
    cout << str << endl; */

    //strings have iterators
    for (auto it = str.begin(); it != str.end(); it++) {
        cout << *it << ' ';
    } cout << '\n';

    str = "Chuckie Tang!!!!";
    cout << str.size() << ' ' << str.length() << endl;
    str.clear();

    str = "CHUCKIE TANG";
    str += "!!!";
    str.append("hello", 2, 2);//string, subpos, sublen
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << ' ';
    } cout << endl;

    str = "CHUCKIE TANG WEEEE";
    string str2 = str.substr(3, 5); //start, length
    size_t pos = str.find("TANG"); //interchangeable basically int
    //string.rfind("E"); //reversefind start from back
    //O(nm) search time
    cout << pos << endl;

    str.erase(str.begin(), str.begin() + 8); //inclusive exclusive
    cout << str << endl;
    str.erase(0, 3); //start, end can use find
    cout << str << endl;

    //string compare
    /*0	They compare equal
    <0	Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
    >0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer. */
    //< 0 = compared string is lower, first string is lower
    str = "a";
    str2 = "b";
    cout << str.compare(str2) << endl; // can also use == and < and >
    cout << (str < str2) << endl;

    //check palindrome
    str = "racecar";
    auto tmp = str;
    for (auto i = 0u; i < tmp.size()/2; i++) {
        swap(tmp[i], tmp[tmp.size() - i - 1]);
    }
    cout << (tmp == str) << endl;

    cout << 'A' - 'A' << endl;
    return 0;
}



