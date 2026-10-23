#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 50;
const int INF = 0x3f3f3f3f;
vector<int> adj[maxn];
int dist[maxn][3];
bool vis[maxn][3];
void bfs(int s, int n, int idx){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i][idx] = INF;
        vis[i][idx] = false;
    }
    vis[s][idx] = true;
    dist[s][idx] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u][idx]) continue;
            vis[u][idx] = true;
            dist[u][idx] = dist[v][idx] + 1;
            q.push(u);
        }
    }
}
int dfs(int x, int d, int p){
    if(d == 0)
        return 1;
    int cont = 0;
    for(auto u : adj[x])
        if(u != p)
            cont += dfs(u, d - 1, x);
    return cont;
}
int main(){
    int a = 1, b = 1, n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, n, 1);
    for(int i = 1; i <= n; i++)
        if(dist[i][1] > dist[a][1])
            a = i;
    bfs(a, n, 1);
    for(int i = 1; i <= n; i++)
        if(dist[i][1] > dist[b][1])
            b = i;
    int diam = dist[b][1];
    bfs(b, n, 2);
    int ans = 0;
    if(diam & 1){
        int c1;
        for(int i = 1; i <= n; i++)
            if((dist[i][1] == dist[i][2] + 1 || dist[i][1] + 1 == dist[i][2]) && dist[i][1] + dist[i][2] == diam)
                c1 = i;
        int c2;
        for(int i = 1; i <= n; i++)
            if((dist[i][1] == dist[i][2] + 1 || dist[i][1] + 1 == dist[i][2]) && dist[i][1] + dist[i][2] == diam && i != c1)
                c2 = i;
        ans = (dfs(c1, (diam - 1) / 2, c2) * dfs(c2, (diam - 1) / 2, c1));
    }else{
        int c;
        for(int i = 1; i <= n; i++)
            if(dist[i][1] == dist[i][2] && dist[i][1] + dist[i][2] == diam)
                c = i;
        int sum = 0;
        for(auto u : adj[c]){
            int aux = dfs(u, diam/2 - 1, c);
            ans -= (aux * (aux - 1)) / 2;
            sum += aux;
        }
        ans += (sum * (sum - 1)) / 2;
    }
    cout << diam + 1 << endl;
    cout << ans << endl;
    return 0;
}