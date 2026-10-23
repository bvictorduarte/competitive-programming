#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n, m;
ll capacity[maxn][maxn];
int parent[maxn];
bool vis[maxn];
vector<int> adj[maxn];
ll bfs(int s, int t) {
    for(int i = 0; i <= n; i++)
        parent[i] = -1;
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, LINF});
    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
ll maxflow(int s, int t) {
    ll flow = 0, new_flow;
    while ((new_flow = bfs(s,t))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
void dfs(int x = 1){
    vis[x] = true;
    for(auto u : adj[x])
        if(!vis[u] && capacity[x][u])
            dfs(u);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(a != n && b != 1)
            adj[a].push_back(b);
        if(b != n && a != 1)
            adj[b].push_back(a);
        capacity[a][b] = 1;
        capacity[b][a] = 1;
    }
    cout << maxflow(1, n) << '\n';
    dfs();
    for(int i = 1; i <= n; i++){
        if(!vis[i])continue;
        for(auto u : adj[i])
            if(!vis[u])
                cout << i << ' ' << u << '\n';
    }
}