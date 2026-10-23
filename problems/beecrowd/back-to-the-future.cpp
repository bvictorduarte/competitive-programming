#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 150;
const int maxm = 5e3 + 50;
struct Edge
{
    int from, to;
};
ll d[maxn], p[maxn];
ll cost[4 * maxm], capacity[4 * maxm];
vector<int> adj[maxn];
Edge edges[4 * maxm];
//inp tem from, to, capacity e cost
vector<tuple<int, int, ll, ll>> inp;
bool inq[maxn];
const ll LINF = 0x3f3f3f3f3f3f3f3f;

void shortest_paths(int n, int v0){
    for(int i = 1; i <= n; i++){
        d[i] = LINF;
        inq[i] = false;
        p[i] = -1;
    }
    d[v0] = 0;
    queue<int> q;
    q.push(v0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int id : adj[u]){
            int v = edges[id].to;
            if (capacity[id] > 0 && d[v] > d[u] + cost[id]){
                d[v] = d[u] + cost[id];
                p[v] = id;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void add_edges(int n, bool directed){
    int id = -1;
    for(int i = 1; i <= n; i++)
        adj[i].resize(0);
    for(auto e : inp){
        int a, b;
        ll cap, c;
        tie(a, b, cap, c) = e;
        edges[++id] = {a, b};
        capacity[id] = cap;
        cost[id] = c;
        adj[a].push_back(id);
        edges[++id] = {b, a};
        capacity[id] = 0;
        cost[id] = -c;
        adj[b].push_back(id);
        if(!directed){
            edges[++id] = {b, a};
            capacity[id] = cap;
            cost[id] = c;
            adj[b].push_back(id);
            edges[++id] = {a, b};
            capacity[id] = 0;
            cost[id] = -c;
            adj[a].push_back(id);
        }
    }
}
ll min_cost_flow(int N, ll K, int s, int t, bool directed){
    add_edges(N, directed);
    ll flow = 0;
    ll cost = 0;
    while(flow < K){
        shortest_paths(N, s);
        if (d[t] == LINF)
            break;
        // find max flow on that path
        ll f = K - flow;
        int cur = t;
        while (cur != s){
            f = min(f, capacity[p[cur]]);
            cur = edges[p[cur]].from;
        }
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s){
            int id = p[cur];
            capacity[id] -= f;
            id ^= 1;
            capacity[id] += f;
            cur = edges[p[cur]].from;
        }
    }
    if (flow < K)
        return -1;
    else
        return cost;
}
int main(){
    int n, m, cont = 0;
    while(cin >> n >> m){
        cont++;
        vector<tuple<int, int, ll>> aux;
        inp.resize(0);
        for(int i = 1; i <= m; i++){
            int a, b;
            ll c;
            cin >> a >> b >> c;
            aux.push_back(make_tuple(a, b, c));
        }
        ll d, k;
        cin >> d >> k;
        for(auto e : aux){
            int a, b;
            ll c;
            tie(a, b, c) = e;
            inp.push_back(make_tuple(a, b, k, c));
        }
        ll ans = min_cost_flow(n, d, 1, n, false);
        cout << "Instancia " << cont << endl;
        if(ans == -1)
            cout << "impossivel\n\n";
        else
            cout << ans << "\n\n";
    }
}