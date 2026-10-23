#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj_ini, adj, mark; // adjacency matrix of graph
vector<pair<int, int>> posi;
const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim() {
    vector<bool> selected(n + 1, false);
    vector<Edge> min_e(n + 1);
    min_e[1].w = 1;
    for (int i = 1; i <= n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        selected[v] = true;
        if (min_e[v].to != -1){
            adj[v].push_back(min_e[v].to);
            adj[min_e[v].to].push_back(v);
        }

        for (int to = 1; to <= n; ++to) {
            if (adj_ini[v][to] < min_e[to].w)
                min_e[to] = {adj_ini[v][to], v};
        }
    }
}
int ans = 0;
vector<bool> vis;
void dfs(int v, int p){
    if(vis[v])
        return;
    vis[v] = true;
    ans += adj_ini[v][p];
    mark[v][p] = 1;
    mark[p][v] = 1;
    for(auto u : adj[v]){

        dfs(u, v);
    }
    for(int i = 1; i <= n; i++){
        dfs(i, v);
    }
}
int main(){
    cin >> n;
    adj_ini.resize(n + 1);
    adj.resize(n + 1);
    vis.resize(n + 1);
    mark.resize(n + 1);
    for(int i = 0; i <= n; i++){
        adj_ini[i].resize(n + 1);
        mark[i].resize(n + 1);
    }
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        posi.emplace_back(a, b);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            double ax = posi[i - 1].first, ay = posi[i - 1].second, bx = posi[j - 1].first, by = posi[j - 1].second;
            adj_ini[i][j] = round(sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by)));
        }
    }
    prim();
    for(int i = 1; i <= n; i++){
        for(auto u : adj[i])
            cout << u << ' ';
        cout << endl;
    }
    dfs(1, 0);
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i < j && mark[i][j])
                cout << i << ' ' << j << endl;
    return 0;
}
