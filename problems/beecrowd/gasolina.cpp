#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2050;
const int maxt = 1e6;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int N, dist[maxn], last[maxn], p, r, c;
ll cap_p[maxn], cap_r[maxn], sum = 0;
vector<tuple<int, ll, ll>> edges;
vector<tuple<int, int, int>> input;
vector<int> adj[maxn];
pair<int, int> parent[maxn];

bool bfs(int s, int t){
    for(int i = 0; i <= N; i++){
        dist[i] = -1;
        parent[i] = make_pair(-1, -1);
    }
    dist[s] = 0;
    queue<int> q({s});
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == t) break;
        for(auto idx : adj[u]){
            int v;
            ll cap, flow;
            tie(v, cap, flow) = edges[idx];
            if((cap - flow > 0) && (dist[v] == -1)){
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v] = {u, idx};
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
            tie(rv, rcap, rflow) = (edges[adj[u][last[u]]^1]);
            rflow -= pushed;
            edges[adj[u][last[u]]^1] = make_tuple(rv, rcap, rflow);
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
        for(int i = 0; i <= N; i++)
            last[i] = 0;
        while(ll f = dfs(s, t))
            mf += f;
    }
    return mf;
}

bool solve(int t){
    edges.resize(0);
    for(int i = 0; i <= N; i++)
        adj[i].resize(0);
    for(int i = 1; i <= r; i++)
        add_edge(0, i, cap_r[i]);
    for(int i = r + 1; i <= p + r; i++)
        add_edge(i, N, cap_p[i - r]);
    for(auto data : input){
        int a, b, l;
        tie(a, b, l) = data;
        if(t >= l){
            add_edge(a, b + r, LINF);
        }
    }
    return dinic(0, N) == sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> p >> r >> c;
    N = p + r + 1;
    for(int i = 1; i <= p; i++){
        cin >> cap_p[i];
        sum += cap_p[i];
    }
    for(int i = 1; i <= r; i++)
        cin >> cap_r[i];
    for(int i = 1; i <= c; i++){
        int b, a, t;
        cin >> b >> a >> t;
        input.push_back(make_tuple(a, b, t));
    }
    int t = 1, b = maxt;
    for(b /= 2; b >= 1; b /= 2){
        while(t + b <= maxt && !solve(t + b)) t += b;
    }
    if(solve(++t))
        cout << t << endl;
    else
        cout << -1 << endl;
    return 0;
}