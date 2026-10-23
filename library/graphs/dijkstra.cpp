ll dist[maxn];
vector<pair<int, ll>> adj[maxn];
bool vis[maxn];
void dijkstra(int s){
    priority_queue<pair<ll, int>> pq;
    for(int i = 1; i <= n; i++){
        dist[i] = LINF;
        vis[i] = false;
    }
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u : adj[a]){
            int b = u.first, w = u.second;
            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                pq.push(make_pair(-dist[b], b));
            }
        }
    }
}