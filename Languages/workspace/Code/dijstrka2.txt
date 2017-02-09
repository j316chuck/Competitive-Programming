memset(vis, 0, sizeof(vis));
memset(cost_a2u, 0x3F, sizeof(cost_a2u));
cost_a2u[A] = make_pair(0, 0);
for (int i = 0; i < MAXV; i++) {
  /* Find the closest unvisited vertex. */
  int u = -1;
  for (int j = 0; j < MAXV; j++) {
    if (vis[j]) {
      continue;
    } else if (u == -1 || cost_a2u[j] < cost_a2u[u]) {
      u = j;
    }
  }

  /* Relax vertex u. */
  vis[u] = true;
  for (int j = 0; j < MAXV; j++) {
    pair<long long, int> rlx = cost_a2u[u];
    rlx.first += cost[u][j].first;
    rlx.second += cost[u][j].second;
    cost_a2u[j] = min(cost_a2u[j], rlx);
  }
}

int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(dist, V);
}