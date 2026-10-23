#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<tuple<int, ll, ll>> edges;
vector<int> adj[maxn];
pair<int, int> parent[maxn];
int n, dist[maxn], last[maxn];

bool bfs(int s, int t) { // find augmenting path
    for(int i = 1; i <= n; i++){
        dist[i] = -1;
        parent[i] = make_pair(-1, -1);
    }
    dist[s] = 0;
    queue<int> q({s});
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break; // stop as sink t reached
        for (auto idx : adj[u]) { // explore neighbors of u
            int v;
            ll cap, flow;
            tie(v, cap, flow) = edges[idx]; // stored in EL[idx]
            if((cap-flow > 0) && (dist[v] == -1)){ // positive residual edge
                dist[v] = dist[u]+1;
                q.push(v);
                parent[v] = {u, idx};
            }
        }
    }
    return dist[t] != -1; // has an augmenting path
}

ll dfs(int u, int t, ll f = LINF){ // traverse from s->t
    if((u == t) || (f == 0)) return f;
    for(; last[u] < (int)adj[u].size(); last[u]++){ // from last edge
        int v;
        ll cap, flow;
        tie(v, cap, flow) = edges[adj[u][last[u]]];
        if(dist[v] != dist[u]+1) continue; // not part of layer graph
        if(ll pushed = dfs(v, t, min(f, cap-flow))) {
            flow += pushed;
            edges[adj[u][last[u]]] = make_tuple(v, cap, flow);
            int rv;
            ll rcap, rflow;
            tie(rv, rcap, rflow) = (edges[adj[u][last[u]]^1]); // back edge
            rflow -= pushed;
            edges[adj[u][last[u]]^1] = make_tuple(rv, rcap, rflow);
            return pushed;
        }
    }
    return 0;
}

// if you are adding a bidirectional edge u<->v with weight w into your
// flow graph, set directed = false (default value is directed = true)
void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return; // safeguard: no self loop
    edges.push_back(make_tuple(v, w, 0)); // u->v, cap w, flow 0
    adj[u].push_back((int)edges.size()-1); // remember this index
    edges.push_back(make_tuple(u, directed ? 0 : w, 0)); // back edge
    adj[v].push_back((int)edges.size()-1); // remember this index
}

ll dinic(int s, int t) {
    ll mf = 0; // mf stands for max_flow
    while (bfs(s, t)) { // an O(V^2*E) algorithm
        for(int i = 1; i <= n; i++)
            last[i] = 0; // important speedup
        while (ll f = dfs(s, t)) // exhaust blocking flow
            mf += f;
    }
    return mf;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
    }
    cout << dinic(1, n) << endl;
    return 0;
}