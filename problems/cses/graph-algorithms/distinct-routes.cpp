#include<bits/stdc++.h>
using namespace std;
const int maxn = 550;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n, dist[maxn], last[maxn];
vector<int> adj[maxn], solve;
vector<tuple<int, ll, ll>> edges;
bool vis[maxn];
bool bfs(int s, int t){
    for(int i = 1; i <= n; i++)
        dist[i] = -1;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(! q.empty()){
        int u = q.front(); q.pop();
        if(u == t) break;
        for(auto idx : adj[u]){
            int v;
            ll cap, flow;
            tie(v, cap, flow) = edges[idx];
            if(cap - flow > 0 && dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

ll dfs(int u, int t, ll f = LINF){
    if((u == t) || (f == 0)) return f;
    for(; last[u] < (int)adj[u].size(); last[u]++){
        int v;
        ll cap, flow;
        tie(v, cap, flow) = edges[adj[u][last[u]]];
        if(dist[v] != dist[u] + 1) continue;
        if(ll pushed = dfs(v, t, min(f, cap - flow))){
            flow += pushed;
            edges[adj[u][last[u]]] = make_tuple(v, cap, flow);
            int rv;
            ll rcap, rflow;
            tie(rv, rcap, rflow) = (edges[adj[u][last[u]] ^ 1]);
            rflow -= pushed;
            edges[adj[u][last[u]] ^ 1] = make_tuple(rv, rcap, rflow);
            return pushed;
        }
    }
    return 0;
}

void add_edge(int u, int v, ll w, bool directed = true){
    if(u == v) return;
    edges.push_back(make_tuple(v, w, 0));
    adj[u].push_back((int)edges.size() - 1);
    edges.push_back(make_tuple(u, directed ? 0 : w, 0));
    adj[v].push_back((int)edges.size() - 1);
}

ll dinic(int s, int t){
    ll mf = 0;
    while(bfs(s, t)){
        for(int i = 1; i <= n; i++)
            last[i] = 0;
        while(ll f = dfs(s, t))
            mf += f;
    }
    return mf;
}

void dfs_sol(int x = 1){
    solve.push_back(x);
    if(solve[(int)solve.size() - 1] == n)
        return;
    vis[x] = true;
    for(auto idx : adj[x]){
        int v;
        ll cap, flow;
        tie(v, cap, flow) = edges[idx];
        if(!vis[v] && flow > 0){
            edges[idx] = make_tuple(v, cap, 0);
            dfs_sol(v);
            if(solve[(int)solve.size() - 1] == n)
                return;
            else
                solve.pop_back();
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1LL);
    }
    ll mf = dinic(1, n);
    cout << mf << endl;
    for(int i = 1; i <= mf; i++){
        for(int i = 1; i <= n; i++)
            vis[i] = false;
        solve.resize(0);
        dfs_sol();
        cout << (int)solve.size() << endl;;
        for(auto u : solve)
            cout << u << ' ';
        cout << endl;
    }
    return 0;
}