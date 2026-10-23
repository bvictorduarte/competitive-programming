#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<tuple<int ,int , ll>> edges[2];
vector<int> adj[maxn][2];
vector<pair<int, int>> g[maxn];
int n, m, sp, tp, tin[maxn], low[maxn], t = 0;
ll dist[maxn][2], ans[maxn];
bool vis[maxn][2], mark[maxn], visited[maxn];
void dijkstra(int op){
    int s = op ? tp : sp;
    for(int i = 1; i <= n; i++)
        dist[i][op] = LINF;
    dist[s][op] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(vis[u][op]) continue;
        vis[u][op] = true;
        for(auto idx : adj[u][op]){
            int v, trash;
            ll w;
            tie(trash, v, w) = edges[op][idx];
            dist[v][op] = min(dist[v][op], dist[u][op] + w);
            pq.push(make_pair(-dist[v][op], v));
        }
    }
}
void build_graph(){
    for(int i = 0; i < (int)edges[0].size(); i++){
            int u, v;
            ll w;
            tie(u, v, w) = edges[0][i];
            if(dist[u][0] + dist[v][1] + w == dist[tp][0]){
                g[u].push_back(make_pair(v, i));
                g[v].push_back(make_pair(u, i));
            }
        }
}
void find_bridges(int v = sp, int id = -1){
    t++;
    tin[v] = t;
    low[v] = t;
    visited[v] = true;
    for(auto e : g[v]){
        int u = e.first, idx = e.second;
        if(!visited[u]){
            find_bridges(u, idx);
            low[v] = min(low[v], low[u]);
        }else{
            if(idx == id) continue;
            low[v] = min(low[v], tin[u]);
        }
    }
    if( v != sp && low[v] == tin[v]) mark[id] = true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> sp >> tp;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges[0].push_back(make_tuple(a, b, w));
        adj[a][0].push_back(edges[0].size() - 1);
        edges[1].push_back(make_tuple(b, a, w));
        adj[b][1].push_back(edges[1].size() - 1);
    }
    dijkstra(0);
    dijkstra(1);
    build_graph();
    find_bridges();
    for(int i = 0; i < (int)edges[0].size(); i++){
        int v, u;
        ll w;
        tie(v, u, w) = edges[0][i];
        if(mark[i]) continue;
        ll nw = dist[tp][0] - dist[v][0] - dist[u][1] - 1;
        ans[i] = nw > 0 ? (w - nw) : -1;
    }
    for(int i = 0; i < m; i++)
        if(ans[i] == -1)
            cout << "NO\n";
        else{
            if(ans[i])
                cout << "CAN " << ans[i] << endl;
            else
                cout << "YES\n";
        }
    return 0;
}