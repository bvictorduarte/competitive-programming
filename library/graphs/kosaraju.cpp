vector<int> adj[maxn][2], ord;
bool vis[maxn][2];
int c = 0, comp[maxn], n;
void add_edge(int a, int b, bool directed){
    adj[a][0].push_back(b);
    adj[b][1].push_back(a);
    if(!directed){
        adj[b][0].push_back(a);
        adj[a][1].push_back(b);
    }
}
void dfs(int x, int f){
    vis[x][f] = true;
    if(f)
        comp[x] = c;
    for(auto u : adj[x][f])
        if(!vis[u][f])
            dfs(u, f);
    if(!f)
        ord.push_back(x);
}
void kosarajus(){
    for(int i = 1; i <= n; i++)
            if(!vis[i][0])
                dfs(i, 0);
    reverse(ord.begin(),ord.end());
    c = 0;
    for(auto u : ord)
        if(!vis[u][1]){
            c++;
            dfs(u, 1);
        }
}