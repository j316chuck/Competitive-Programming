/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
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

//Arrays are special:
//they are always passed as a pointer to the first element of the array.


void array_mutate(int arr[], int n) {//const// int arr[]) { //if constant then read only for array including values
    cout << sizeof(arr) /sizeof(arr[0]) << endl;
    arr[0] = 0;
}

/*
void by_pointer(int *p, int size);
void by_pointer(int p[], int size);
void by_pointer(int p[7], int size);
*/

void array_mutate2(int (&arr)[4]) {
    arr[0] = 3;
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << ' ';
    } cout << endl;
}

void two_dimensional_mutate(int arr[][4]); //second - last dimension must be specified
int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    int arr[] = {1, 2, 3, 4};
    array_mutate(arr, 4);
    printf("Mutating first value of an array: %d\n", arr[0]);
    array_mutate2(arr);
    printf("Mutating first value of an array: %d\n", arr[0]);
    int arrays[4] = {1, 2, 3, 4};
    int myarray[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &myarray[i]);
    }
    int twoDimArray[2][4] = { { 6, 0, 9, 6 } , { 2, 0, 1, 1 } }; //2d array
    printf("%d\n", sizeof(myarray)/sizeof(myarray[0])); //The sizeof is a keyword, but it is a compile-time operator that determines the size, in bytes, of a variable or data type.

    //pointer and array operations
    //pointers and arrays
    int numbers[5];
    int * p;
    //p = numbers;  *p = 10;
    p = &numbers[0]; *p = 10;
    p++;  *p = 20;
    p = &numbers[2];  *p = 30;
    p = numbers + 3;  *p = 40;
    p = numbers;  *(p+4) = 50;

    //numbers = & numbers[0]; numbers + 3 = &numbers[3]
    //p++ = advance in array, *(p+4) = numbers[4];
    for (int n=0; n<5; n++)
        cout << numbers[n] << ", ";
    char str[] = "hello";
    char *ptr = str;
    for (int i = 0; i < 5; i++) {
        cout << *ptr;
        ptr++;
    } cout <<endl;
    //numbers can be reassigned but pointers cannot be.
    //int number[5] = {1,2,3,4};
    //number = {1, 2, 3};
    //numbers = &numbers[0], numbers + 1 = &numbers[1];
    rotate(numbers, numbers + 1, numbers + 5);
    for (int n=0; n<5; n++)
        cout << numbers[n] << ", ";
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



