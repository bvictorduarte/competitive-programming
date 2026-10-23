#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 550;
int n;
ll dist[maxn], rdist[maxn];
vector<pair<int, ll>> adj[maxn], radj[maxn];
vector<tuple<int, int, ll>> edges;
map<pair<int, int>, bool> mp;
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
            if(mp[make_pair(a, b)])
                continue;
            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                pq.push(make_pair(-dist[b], b));
            }
        }
    }
}
void rdijkstra(int s){
    priority_queue<pair<ll, int>> pq;
    for(int i = 1; i <= n; i++){
        rdist[i] = LINF;
        vis[i] = false;
    }
    rdist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u : radj[a]){
            int b = u.first, w = u.second;
            if(rdist[a] + w < rdist[b]){
                rdist[b] = rdist[a] + w;
                pq.push(make_pair(-rdist[b], b));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    while(cin >> n >> m && n && m){
        int s, t;
        cin >> s >> t;
        s++;
        t++;
        for(int i = 1; i <= m; i++){
            int a, b;
            ll w;
            cin >> a >> b >> w;
            a++;
            b++;
            edges.push_back(make_tuple(a, b, w));
            adj[a].push_back(make_pair(b, w));
            radj[b].push_back(make_pair(a, w));
        }
        mp.clear();
        dijkstra(s);
        rdijkstra(t);
        for(auto e : edges){
            int a, b;
            ll w;
            tie(a, b, w) = e;
            if(dist[a] + rdist[b] + w == dist[t])
                mp[make_pair(a, b)] = true;
        }
        dijkstra(s);
        if(dist[t] != LINF)
            cout << dist[t] << endl;
        else
            cout << -1 << endl;
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            radj[i].resize(0);
        }
        edges.resize(0);
    }
}