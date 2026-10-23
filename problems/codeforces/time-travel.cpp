#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[maxn];
bool vis[maxn];
vector<int> v[maxn];
int dist[maxn];
void dijkstra(int n){
    for(int i = 2; i <= n; i++)
        dist[i] = maxn;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        int a = pq.top().second; pq.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto p : adj[a]){
            int b = p.first, s = p.second;
            int idx = upper_bound(v[s].begin(), v[s].end(), dist[a]) - v[s].begin();
            if(idx < (int)v[s].size() && dist[b] > v[s][idx]){
                dist[b] = v[s][idx];
                pq.push({-dist[b], b});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= t; i++){
        int m;
        cin >> m;
        for(int j = 1; j <= m; j++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
    }
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        int a;
        cin >> a;
        v[a].push_back(i);
    }
    dijkstra(n);
    if(dist[n] == maxn)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
    return 0;
}