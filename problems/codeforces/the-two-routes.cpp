#include<bits/stdc++.h>
using namespace std;
const int maxn = 450;
const int INF = 0x3f3f3f3f;
int n, m;
int adj_matrix[maxn][maxn];
int dist[maxn];
bool vis[maxn];
vector<int> adj[maxn];
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b]  = adj_matrix[b][a] = 1;
    }
    int aux = 0;
    if(adj_matrix[1][n])
        aux = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(adj_matrix[i][j] ^ aux){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    bfs(1);
    if(dist[n] == INF)
        cout << -1 << endl;
    else
        cout << max(1, dist[n]) << endl;
    return 0;
}