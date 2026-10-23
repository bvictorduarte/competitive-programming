#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const ll INF = 0x3f3f3f3f;
vector<int> adj[maxn];
int dist[maxn], n;
bool vis[maxn];
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
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        adj[i].push_back(a);
        if(i != n)
            adj[i].push_back(i + 1);
        if(i != 1)
            adj[i].push_back(i - 1);
    }
    bfs(1);
    for(int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}