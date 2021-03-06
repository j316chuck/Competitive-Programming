#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INFTY = 1<<30;
const int MAXN = 3005;
int N, M, K;
vector<int> adj[MAXN];
map<ll, bool> mp;
int dist[MAXN][MAXN];
int par[MAXN][MAXN];
int order[MAXN];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mp[(ll)a*100000000 + b*10000 + c] = true;
	}

	queue<pii> q;
	q.push(pii(1, 1));

	dist[1][1] = 1;
	while (!q.empty())
	{
		int a = q.front().first, b = q.front().second;
		q.pop();

		for (int i = 0; i < adj[b].size(); i++)
		{
			int next = adj[b][i];
			if (par[b][next] == 0 && !mp[(ll)a*100000000 + b*10000 + next])
			{
				dist[b][next] = dist[a][b] + 1;
				par[b][next] = a;
				q.push(pii(b, next));
			}
		}
	}

	int ans = INFTY, a = 0, b = N;
	for (int i = 1; i <= N; i++)
		if (dist[i][N] > 0 && dist[i][N] < ans)
		{
			ans = dist[i][N];
			a = i;
		}

	if (ans == INFTY)
	{
		cout << "-1\n";
		return 0;
	}

	ans--;

	for (int i = 0; i <= ans; i++)
	{
		order[ans - i] = b;
		int temp = a;
		a = par[a][b];
		b = temp;
	}

	cout << ans << "\n";
	for (int i = 0; i <= ans; i++)
		cout << order[i] << " ";

	return 0;
}
