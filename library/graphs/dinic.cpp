bool bfs(int s, int t){
    for(int i = 1; i <= n; i++)
        dist[i] = -1;
    dist[s] = 0;
    queue<int> q({s});
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (u == t) break;
        for (auto idx : adj[u]){
            int v;
            ll cap, flow;
            tie(v, cap, flow) = edges[idx];
            if((cap-flow > 0) && (dist[v] == -1)){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

ll dfs1(int u, int t, ll f = LINF){
    if((u == t) || (f == 0)) return f;
    for(; last[u] < (int)adj[u].size(); last[u]++){
        int v;
        ll cap, flow;
        tie(v, cap, flow) = edges[adj[u][last[u]]];
        if(dist[v] != dist[u]+1) continue;
        if(ll pushed = dfs1(v, t, min(f, cap-flow))) {
            flow += pushed;
            edges[adj[u][last[u]]] = make_tuple(v, cap, flow);
            int rv;
            ll rcap, rflow;
            tie(rv, rcap, rflow) = (edges[adj[u][last[u]]^1]);
            rflow -= pushed;
            edges[adj[u][last[u]]^1] = make_tuple(rv, rcap, rflow);
            return pushed;
        }
    }
    return 0;
}

void add_edge(int u, int v, ll w, bool directed = true){
    if (u == v) return;
    edges.push_back(make_tuple(v, w, 0));
    adj[u].push_back((int)edges.size()-1);
    edges.push_back(make_tuple(u, directed ? 0 : w, 0));
    adj[v].push_back((int)edges.size()-1);
}

ll dinic(int s, int t){
    ll mf = 0;
    while(bfs(s, t)){
        for(int i = 1; i <= n; i++)
            last[i] = 0;
        while(ll f = dfs1(s, t))
            mf += f;
    }
    return mf;
}