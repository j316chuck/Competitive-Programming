#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("repair.in", "r", stdin);
    int n, x; long long total = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
    for (int i = 0; i < n-1; i++) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        total += a + b;
        pq.push(a+b);
    }
    printf("%d\n", total);
}
