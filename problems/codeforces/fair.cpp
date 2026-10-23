#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int maxk = 1e2 + 50;
const int INF = 0x3f3f3f3f;
vector<int> adj[maxn], v[maxn];
int dist[maxn], a[maxn];
int n;
bool vis[maxn];
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    for(int i = 1; i <= n; i++)
        if(a[i] == s){
            vis[i] = true;
            dist[i] = 0;
            q.push(i);
        }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    for(int i = 1; i <= n; i++)
        v[i].push_back(dist[i]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, k, s;
    cin >> n >> m >> k >> s;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= k; i++)
        bfs(i);
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
        int sum = 0;
        for(int j = 0; j < s; j++)
            sum += v[i][j];
        cout << sum << ' ';
    }
    cout << endl;
    return 0;
}