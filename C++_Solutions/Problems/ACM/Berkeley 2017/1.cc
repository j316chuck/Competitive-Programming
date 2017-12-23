#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stdarg.h>
#include <cstring>
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
//#include <bits/stdc++.h>
//#include <contest.h>
using namespace std;

int main() {
    //freopen("input.in", "r", stdin);
    int n1, n2;
    cin >> n1 >> n2;
    if (n2 > n1) {
        int positive = n2 - n1;
        int negative = n1 + 360 - n2;
        if (positive <= negative) {
            cout << positive << endl;
        } else {
            cout << -negative << endl;
        }
    } else if (n2 == n1) {
        cout << 0 << endl;
    } else if (n2 < n1) {
        int positive = 360 - n1 + n2;
        int negative = n1 - n2;
        if (positive <= negative) {
            cout << positive << endl;
        } else {
            cout << -negative << endl;
        }
    }
    return 0;
}


