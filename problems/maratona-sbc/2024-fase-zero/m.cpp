#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int INF  = 0x3f3f3f3f;
vector<int> adj[maxn];
int dist[maxn], n, m;
bool visited[maxn];
int bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        visited[i] = false;
    }
    dist[s] = 0;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u: adj[v]){
            if(visited[u])continue;
            visited[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++)
        if(i != s)
            ans = max(ans, dist[i]);
    return ans;
}
int main(){
    int d;
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int max_c = -1;
    for(int i = 1; i <= n; i++){
        int aux = bfs(i);
        max_c = max(max_c, aux);
    }
    if(max_c > 2*d + 1)
        cout << 0 << ' ' << 0 <<endl;
    else
        cout << 2*d + 1 - max_c << ' ' << 2*d + 1 - max_c  << endl;
    return 0;
}