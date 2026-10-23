#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
int n, m;
vector<int> adj[maxn];
vector<int> radj[maxn];
int dist[maxn], p[maxn];
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
bool tem(int v, int viz){
    for(auto u : radj[v]){
        if(u == viz)
            continue;
        if(dist[v] - 1 == dist[u])
            return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        radj[a].push_back(b);
    }
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> p[i];
    bfs(p[k]);
    int ans_min = 0, ans_max = 0;
    for(int i = 2; i <= k; i++){
        if(dist[p[i - 1]] - 1 != dist[p[i]]){
            ans_min++;
            ans_max++;
        }else if(tem(p[i - 1], p[i]))
            ans_max++;
    }
    cout << ans_min << ' ' << ans_max << endl;
    return 0;
}