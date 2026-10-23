#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
bool vis[maxn][maxn];
ll dist[maxn][maxn], p[maxn];
vector<pair<int, int>> adj[maxn]; 
int n, m;
void dijkstra(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            dist[i][j] = LINF;
            vis[i][j] = false;
        }
    dist[1][1] = 0;
    priority_queue<pair<pair<ll, ll>, pair<int, int>>> pq;
    pq.push({{0, -p[1]}, {1, 1}});
    while(!pq.empty()){
        int v = pq.top().second.first, s = pq.top().second.second; pq.pop();
        if(vis[v][s]) continue;
        vis[v][s] = true;
        for(auto e : adj[v]){
            int u = e.first;
            ll w = e.second;
            if(dist[u][s] > dist[v][s] + w * p[s]){
                dist[u][s] = dist[v][s] + w * p[s];
                pq.push({{-dist[u][s], -p[s]}, {u, s}});
            }
            if(dist[u][u] > dist[v][s] + w * p[s]){
                dist[u][u] = dist[v][s] + w * p[s];
                pq.push({{-dist[u][u], -p[u]}, {u, u}});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        adj[i].resize(0);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int a, b;
            ll w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        for(int i = 1; i <= n; i++)
            cin >> p[i];
        dijkstra();
        ll ans = LINF;
        for(int i = 1; i <= n; i++)
            ans = min(ans, dist[n][i]);
        cout << ans << endl;
    }
    return 0;
}