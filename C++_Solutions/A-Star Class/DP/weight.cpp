#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;
int h, n, len;
bool visited[maxn];

void update() {
    for (int i = 0; i + len <= h; i++) {
        if (visited[i]) {
            visited[i+len] = true;
        }
    }
}

int main() {
    //freopen("weight.in", "r", stdin);
    scanf("%d %d", &h, &n);
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    for (int i = 0; i < n; i++) {
        scanf("%d", &len);
        update();
    }
    int mx = 0;
    for (int i = 1; i <= h; i++) {
        if (visited[i]) {
            mx = max(mx, i);
        }
    }
    printf("%d\n", mx);
    return 0;
}
