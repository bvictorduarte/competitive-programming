#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
ll dist[maxn], v[maxn];
int n;
vector<pair<int, ll>> adj[maxn];
vector<pair<int, int>> edges;
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
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int m, k;
    double p;
    while(cin >> n >> m >> k >> p){
        edges.resize(0);
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            edges.push_back(make_pair(a, b));
        }
        int a;
        cin >> a;
        for(int i = 1; i <= a; i++){
            int pos;
            cin >> pos;
            v[pos]++;
        }
        for(auto e : edges){
            int a, b;
            ll w;
            a = e.first;
            b = e.second;
            w = v[a] + v[b];
            adj[a].push_back(make_pair(b, w));
            adj[b].push_back(make_pair(a, w));
        }
        int s, t;
        cin >> s >> t;
        dijkstra(s);
        ll tam = (dist[t] + v[s] + v[t]) / 2;
        if(tam > k)
            printf("0.000\n");
        else{
            double ans = pow(p, tam);
            printf("%.3lf\n", ans);
        }
        for(int i = 1; i <= n; i++){
            v[i] = 0;
            adj[i].resize(0);
        }
    }
    return 0;
}