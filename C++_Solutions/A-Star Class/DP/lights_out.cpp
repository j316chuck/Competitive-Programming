/*
1. vector<int>
2. xor every element
3. dp[i][j] to find min element i = current element, j = expression, affects i+1; //n -l + 2;
4. at the end find max element
5. initialize max; everything else = min;
6. calculate bitset...
7. from 2 - t-l+1;
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
int n, l;
string s1, s2;
vector<int> str;
vector<int> tine;
int state, tne;
int dp[100][128];

int build_num(int st) {
    int num = 0;
    for (int i = st; i < st + l; i++) {
        num = (num << 1) + str[i];
    }
    return num;
}

int build_bits(int k) {

}


int main() {
    freopen("lights_out.in", "r", stdin);
    scanf("%d %d ", &n, &l);
    char c;
    str.resize(n), tine.resize(l);
    for (int i = 1; i <= n; i++) {
        scanf("%c ", &c);
        str[i] = c - '0';
        state = (state << 1) + (c - '0');
    }
    for (int i = 1; i <= l; i++) {
        scanf("%c ", &c);
        tine[i] = c - '0';
        tne = (tne << 1) + (c - '0');
    }
    if (n < l) {
        printf("0\n");
        return 0;
    }
    int cur = build_num(1);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 128; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][cur] = __builtin_popcountll(cur);
    int nopress, press, sum;
    //nopress = str[1] == 1 ? cur/2 : cur;
    //cout << nopress << endl;
    for (int i = 1; i <= n-l; i++) {
        for (int k = 0; k < 128; k++) if (dp[i][k] != INF) {
            nopress = str[i] == 1 ? k/2 : k;
            nopress = (nopress << 1) + str[i+1];
            sum = dp[i][k] + change() + str[i+l];
            dp[i+1][nopress] = min(dp[i+1][nopress], sum);
            press = str;
        }
    }
    //max (dp[n-l+2])
    //dp[1-> 2 2->3 n
}
