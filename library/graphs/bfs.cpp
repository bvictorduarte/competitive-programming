vector<int> adj[maxn];
int dist[maxn];
bool vis[maxn];
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}