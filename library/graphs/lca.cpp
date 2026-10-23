int n;
int dp[maxn][30], dep[maxn];

void pre_compute(){
    for(int j = 1; j <= ceil(log2(maxn)); j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

int ancestor(int x, int k){
    for(int j = ceil(log2(maxn)); j >= 0; j--)
        if(k & (1 << j))
            x = dp[x][j];
    return x;
}

int lca(int a,int b){
    if(dep[a] < dep[b])
        swap(a, b);
    a = ancestor(a, dep[a]-dep[b]);
    if(a == b)
        return a;
    for(int i = ceil(log2(maxn)); i >= 0; i--)
        while(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    return dp[a][0];
}