#include <bits/stdc++.h>
#define MAXN 1000005

using namespace std;

vector<int> adj[MAXN];
bool vis[MAXN];

pair<int, int> min_cuts_min_height(int v, int maxdiam) {
    //cout << v << endl;
    vis[v] = 1;
    pair<int,int> ans;
    ans.first = 0;
    ans.second = 0;
    vector<int> cheights;
    for(int i = 0; i<adj[v].size(); i++) {
        if (!vis[adj[v][i]]) {
            pair<int,int> p = min_cuts_min_height(adj[v][i],maxdiam);
            ans.first += p.first;
            cheights.push_back(p.second);
        }
    }
    if (cheights.size () > 0) {
        sort (cheights.begin (),cheights.end ());
        reverse (cheights.begin (),cheights.end ());
        int i;
        for(i = 0; i < cheights.size()-1 &&
                  cheights[i] + cheights[i+1] + 2 > maxdiam; i++);
        if (i < cheights.size()-1) {
            ans.first += i;
            ans.second = cheights[i]+1;
        } else if (cheights[i] + 1 > maxdiam) {
            ans.first += i+1;
            ans.second = 0;
        } else {
            ans.first += i;
            ans.second = cheights[i]+1;
        }
    }
    return ans;
}

int main () {
    freopen("calisthenics.in", "r", stdin);
    //FILE *fin = fopen ("exercise.in","r");
    //FILE *fout = fopen ("exercise.out","w");
    int N, S;

    scanf ("%d%d",&N,&S);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        scanf ("%d%d",&a,&b);
        a--; b--;
        adj[a].push_back (b);
        adj[b].push_back (a);
    }
    int hi = N-1, lo = 0;
    while (lo < hi) {
        int g = (hi + lo)/2;
        for (int i = 0; i < N; i++) vis[i] = 0;
        pair<int,int> p = min_cuts_min_height (0, g);
        if(p.first > S) lo = g+1;
        else               hi = g;
    }
    printf ("%d\n",lo);
    //fclose (fin);
    //fclose (fout);
    return 0;
}
