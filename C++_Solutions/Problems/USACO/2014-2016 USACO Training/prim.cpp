long long result = 0;
vector<bool> used(N, false);
vector<int> D(N, 0);
for (int i = 0; i < N; i++) {
  /* Find the index, j, of the 'furthest' node from the current spanning tree. */
  int j = -1;
  for (int k = 0; k < N; k++) {
    if (used[k]) continue;
    if (j == -1 || D[k] > D[j]) {
      j = k;
    }
  }

  /* Update the result and 'relax' the edges out of vertex j. */
  result += D[j];
  used[j] = true;
  for (int k = 0; k < N; k++) {
    D[k] = max(D[k], A[j] ^ A[k]);
  }
}

/*


  d[0] = 0;
    int total = 0;

    for(int i = 1; i <= n; i++){
        int min_index  = -1, min_value = INT_MAX;
        for(int j = 0; j < n; j++){
            if(intree[j] == false && d[j] < min_value){
                min_value = d[j];
                min_index = j;
            }
        }
        if(min_index == -1)
            break;

        intree[min_index] = true;
        total+=min_value;
        //cou

        for(int j = 0; j < n; j++){
            if(graph[min_index][j]!=0 && intree[j] == false){
                if(graph[min_index][j] < d[j]){
                    d[j] = graph[min_index][j];
                    parent[j] = min_index;
                }
            }
        }
    }

  */