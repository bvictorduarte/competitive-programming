#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 250;
struct Edge
{
    int from, to;
    ll capacity, cost;
};
ll cost[2 * maxn][2 * maxn], capacity[2 * maxn][2 * maxn], d[2 * maxn], p[2 * maxn];
vector<int> adj[2 * maxn];
vector<Edge> edges;
bool inq[2 * maxn];
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
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]){
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
 
ll min_cost_flow(int N, ll K, int s, int t){
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
    ll flow = 0;
    ll cost = 0;
    while (flow < K) {
        shortest_paths(N, s);
        if (d[t] == LINF)
            break;
        // find max flow on that path
        ll f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s){
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    if (flow < K)
        return -1;
    else
        return cost;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int a = 2; a <= n + 1; a++){
        edges.push_back({1, a, 1LL, 0});
        edges.push_back({n + a, 2 * n + 2, 1LL, 0});
        for(int b = 1; b <= n; b++){
            ll c;
            cin >> c;
            edges.push_back({a, n + 1 + b, 1LL, c});
        }
    }
    ll cost = min_cost_flow(2 * n + 2, n, 1, 2 * n + 2);
    cout << cost << endl;
    for(int a = 1; a <= n; a++)
        for(int b = 1; b <= n; b++)
            if(!capacity[1 + a][n + 1 + b])
                cout << a << ' ' << b << endl;
}