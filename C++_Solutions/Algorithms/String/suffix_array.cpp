#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const int MAXM = 20;

char A[MAXN];
int P[MAXM][MAXN];

struct entry {
    int nr[2], index;
};

bool cmp (const entry &a, const entry &b) {
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1]) : a.nr[0] < b.nr[0];
}

int main(){
    freopen("suffix_array.in", "r", stdin);
    scanf("%s", A);
    int n = strlen(A);
    for (int i = 0; i < n; i++) {
        P[0][i] = A[i] - 'a';
    }

    entry L[MAXN];
    int stp, cnt; //cnt >> 1 just for safety
    for (stp = 1, cnt = 1; cnt >> 1 < n; cnt <<= 1, stp++) {
        for (int i = 0; i < n; i++) {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i + cnt < n ? P[stp-1][i + cnt] : -1;
            L[i].index = i;
        }
        sort(L, L+n, cmp);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1]) {
                P[stp][L[i].index] = P[stp][L[i-1].index];
            } else {
                P[stp][L[i].index] = ++num;
            }
        }
    }
    int SA[n+1];
    for (int i = 0; i < n; i++) {
        SA[i] = P[stp-1][i];
    }
    for (int i = 0; i < n; i++) {
        cout << SA[i] << " ";
    } cout << endl;
    //suffix array found at stp - 1
    for (int i = 0; i < stp; i++) {
        for (int j = 0 ; j < n;j++) {
            cout << P[i][j] << " ";
        } cout << endl;
    }
}


