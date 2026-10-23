#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n;
int dist[maxn], last[maxn];
vector<int> adj[maxn];
vector<tuple<int, ll, ll>> edges;
bool bfs(int s, int t){
    for(int i = 1; i <= n; i++)
        dist[i] = -1;
    dist[s] = 0;
    queue<int> q({s});
    while(!q.empty()){
        int u = q.front(); q.pop();
        if( u == t) break;
        for(auto idx : adj[u]){
            int v;
            ll cap, flow;
            tie(v, cap, flow) = edges[idx];
            if((cap - flow > 0) && (dist[v] == -1)){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

ll dfs1(int u, int t, ll f = LINF){
    if(u == t || f == 0)
        return f;
    for(; last[u] < (int)adj[u].size(); last[u]++){
        int v;
        ll cap, flow;
        tie(v, cap, flow) = edges[adj[u][last[u]]];
        if(dist[v] != dist[u] + 1)
            continue;
        if(ll pushed = dfs1(v, t, min(f, cap - flow))){
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
        while(ll f = dfs1(s, t))
            mf += f;
    }
    return mf;
}
int main(){
    map<string, int> mp;
    mp["XXL"] = 2;
    mp["XL"] = 3;
    mp["L"] = 4;
    mp["M"] = 5;
    mp["S"] = 6;
    mp["XS"] = 7;
    int t;
    cin >> t;
    while(t--){
        int N, m;
        cin >> N >> m;
        ll acap = N / 6;
        for(int i = 2; i <= 7; i++)
            add_edge(1, i, acap);
        for(int i = 8; i <= 7 + m; i++){
            string s1, s2;
            cin >> s1 >> s2;
            add_edge(mp[s1], i, 1);
            add_edge(mp[s2], i, 1);
            add_edge(i, 7 + m + 1, 1);
        }
        n = 8 + m;
        if(dinic(1, 8 + m) == m)
            cout << "YES\n";
        else
            cout << "NO\n";
        edges.resize(0);
        for(int i = 1; i <= m + 8; i++)
            adj[i].resize(0);
    }
}