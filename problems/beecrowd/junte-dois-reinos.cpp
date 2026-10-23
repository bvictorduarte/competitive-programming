#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e4 + 50;
vector<int> adj[2][maxn];
int dist[maxn], dist2[2][maxn], mdist[2][maxn], diam[2];
void dfs(int v, int p, int g){
    dist[v] = dist[p] + 1;
    for(auto u : adj[g][v]){
        if(u == p)
            continue;
        dfs(u, v, g);
    }
}
tuple<int, int, int> fdiam(int g, int n){
    int a = 1;
    dfs(1, 0, g);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[a])
            a = i;
    int b = a;
    dfs(a, 0, g);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[b])
            b = i;
    return make_tuple(a, b, dist[b]);
}
void compute_dists(int g, int n){
    int a, b;
    tie(a, b, diam[g]) = fdiam(g, n);
    dfs(a, 0, g);
    for(int i = 1; i <= n; i++)
        dist2[0][i] = dist[i];
    dfs(b, 0, g);
    for(int i = 1; i <= n; i++)
        dist2[1][i] = dist[i];
    for(int i = 1; i <= n; i++)
        mdist[g][i] = max(dist2[0][i], dist2[1][i]);
}
int main(){
    int n, q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dist[0] = -1;
    while(cin >> n >> q){
        for(int i = 1; i <= n; i++)
            adj[0][i].resize(0);
        for(int i = 1; i <= q; i++)
            adj[1][i].resize(0);
        for(int i = 1; i <= n - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[0][a].push_back(b);
            adj[0][b].push_back(a);
        }
        for(int i = 1; i <= q - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[1][a].push_back(b);
            adj[1][b].push_back(a);
        }
        compute_dists(0, n);
        compute_dists(1, q);
        double ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= q; j++){
                int tam = max(max(diam[0], diam[1]), mdist[0][i] + mdist[1][j] + 1);
                ans += tam;
            }
        printf("%.3lf\n", ans / (n * q));
    }
    return 0;
}