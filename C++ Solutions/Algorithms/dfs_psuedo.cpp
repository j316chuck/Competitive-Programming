void dfs() {
    if (wrong) {return;}
    if (success) {eval(success) return;}
    for loop all possible next states:
            dfs(next state)
}
//with memoization
int memo[][]; //can also use a map!!!

void dfs(i, j) {
    if (memo[i][j] != -1) return;
    if (wrong) {eval(wrong) return;}
    if (success) {eval(success) return;}
    for loop all possible next states:
            dfs(next state)
}
