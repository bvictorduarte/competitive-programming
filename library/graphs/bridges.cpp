vector<int> adj[maxn];
vector<pair<int, int>> bridges;
bool vis[maxn];
int tin[maxn], low[maxn], t = 0;
void dfs(int v, int dad){
    t++;
    tin[v] = t;
    low[v] = t;
    vis[v] = true;
    for(auto u : adj[v]){
        if(!vis[u]){
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        }else{
            if(u == dad) continue;
            low[v] = min(low[v], tin[u]);
        }
    }
    if(v != 1 && low[v] == tin[v]) bridges.push_back(make_pair(v, dad));
}