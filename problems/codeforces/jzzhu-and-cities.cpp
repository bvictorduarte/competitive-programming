#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 50;
const int maxm = 5e5 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, tin[maxn], low[maxn], t = 0, in_degree[maxn], ans = 0;
vector<int> adj[maxn], g[maxn];
ll dist[maxn];
bool vis[maxn], mark[maxm], vis1[maxn];
tuple<int, int, ll> edges[maxm];
void dijkstra(){
    for(int i = 2; i <= n; i++)
        dist[i] = LINF;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto idx : adj[a]){
            int b = get<0>(edges[idx]) == a ? get<1>(edges[idx]) : get<0>(edges[idx]);
            ll w = get<2>(edges[idx]);
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                pq.push({-dist[b], b});
            }
        }
    }
}
void build_graph(){
    for(int idx = 1; idx <= m + k; idx++){
        int a, b;
        ll w;
        tie(a, b, w) = edges[idx];
        if(dist[a] + w == dist[b]){
            g[a].push_back(idx);
            in_degree[b]++;
        }else if(dist[b] + w == dist[a]){
            g[b].push_back(idx);
            in_degree[a]++;
        }
        else if(idx > m)
            ans++;
    }
}
int solve(){
    for(auto i : g[1]){
        if(i <= m) continue;
        int b = get<1>(edges[i]);
        if(in_degree[b] > 1){
            ans++;
            in_degree[b]--;
        }
    }
    return ans;
}

// Do not work because there can be multiple roads between two cities
/*void find_bridges(int v = 1, int dad = 0, int idx = 0){
    t++;
    tin[v] = t;
    low[v] = t;
    vis1[v] = true;
    for(auto i : g[v]){
        int u = get<0>(edges[i]) == v ? get<1>(edges[i]) : get<0>(edges[i]);
        if(!vis1[u]){
            find_bridges(u, v, i);
            low[v] = min(low[v], low[u]);
        }else{
            if(u == dad) continue;
            low[v] = min(low[v], tin[u]);
        }
    }
    if(v != 1 && low[v] == tin[v]) mark[idx] = true;
}*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(i);
        adj[b].push_back(i);
        edges[i] = make_tuple(a, b, w);
    }
    for(int i = m + 1; i <= m + k; i++){
        int b;
        ll w;
        cin >> b >> w;
        adj[1].push_back(i);
        adj[b].push_back(i);
        edges[i] = make_tuple(1, b, w);
    }
    dijkstra();
    build_graph();
    cout << solve() << endl;
    return 0;
}