#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
const int INF = 0x3f3f3f3f;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
vector<int> towers;
ll dist[maxn], atk[maxn], rng[maxn];
ll peso[maxn];
int n;
bool vis[maxn];
vector<pair<int, int>> edges;
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u] || dist[v] > rng[s]) continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}

vector<pair<int, ll>> adj2[maxn];
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
        for(auto u : adj2[a]){
            int b = u.first;
            ll w = u.second;
            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                pq.push(make_pair(-dist[b], b));
            }
        }
    }
}
void reset(){
    towers.resize(0);
    edges.resize(0);
    for(int i = 1; i <= n; i++){
        peso[i] = 0;
        adj2[i].resize(0);
        adj[i].resize(0);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, cont = 0;
    cin >> t;
    while(t--){
        int m, s;
        cin >> n >> m >> s;
        reset();
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            if(a != s && b != s){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            edges.push_back(make_pair(a, b));
        }
        int p;
        cin >> p;
        for(int i = 1; i <= p; i++){
            int a;
            ll b, c;
            cin >> a >> b >> c;
            atk[a] = b;
            rng[a] = c;
            bfs(a);
            for(int i = 1; i <= n; i++)
                if(dist[i] != INF && dist[i] <= rng[a])
                    peso[i] += atk[a];
        }
        for(auto e : edges){
            int a = e.first, b = e.second;
            adj2[a].push_back(make_pair(b, peso[a] + peso[b]));
            adj2[b].push_back(make_pair(a, peso[a] + peso[b]));
        }
        dijkstra(s);
        int tdmg = 0, q;
        cin >> q;
        for(int i = 1; i <= q; i++){
            int monster, healthy;
            cin >> monster >> healthy;
            if(healthy > (dist[monster] + peso[monster]) / 2)
                tdmg++;
        }
        cout << "Caso #" << ++cont << ": ";
        cout << tdmg << endl;
    }
    return 0;
}