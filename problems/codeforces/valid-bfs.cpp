#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
vector<int> adj[maxn];
int dist[maxn], n, t = 1, tin[maxn], tin_inp[maxn];
bool vis[maxn];

void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    vis[s] = true;
    dist[s] = 0;
    tin[s] = t;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : adj[v]) {
            if (vis[u]) continue;
            vis[u] = true;
            tin[u] = ++t;
            dist[u] = dist[v]+1;
            q.push(u);
        }
    }
}

bool comp(int a, int b){
    return tin_inp[a] < tin_inp[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        tin_inp[a] = i;
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), comp);
    bfs(1);
    bool ok = true;
    for(int i = 1; i <= n; i++)
        if(tin[i] != tin_inp[i])
            ok = false;
    if(ok)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}


