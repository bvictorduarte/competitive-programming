#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
int n;
vector<int> adj[maxn];
int vis[maxn], par[maxn], fc = 0;
int dist[maxn];
void dfs(int x, int p){
    if(vis[x] || fc){
        if(!fc)
            fc = x;
        return;
    }
    par[x] = p;
    vis[x] = true;
    for(auto u : adj[x])
        if(u != p)
            dfs(u, x);
}
pair<int, int> solve(int x){
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        par[i] = 0;
    }
    fc = 0;
    dfs(x, 0);
    int cont = 1;
    int it = fc;
    if(x == fc)
        return make_pair(0, fc);
    while(par[it] != x){
        it = par[it];
        cont++;
    }
    return make_pair(cont, fc);
}
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        dist[i] = INF;
    }
    q.push(s);
    dist[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u])
                continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            adj[i].resize(0);
        int a, b;
        cin >> b >> a;
        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pair<int, int> aux = solve(a);
        int sa = aux.first, fca = aux.second;
        bfs(b);
        if(sa < dist[fca])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}