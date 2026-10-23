#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
vector<pair<int, ll>> adj[maxn];
bool vis[maxn];
ll dist[maxn], q_min = 0, dp1[maxn], dp2[maxn], dp3[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }
    for(int i = 2; i <= n; i++)
        dist[i] = LINF;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, 1));
    dp1[1] = 1;
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        if(vis[v]) continue;
        vis[v] = true;
        for(auto p : adj[v]){
            int u = p.first;
            ll w = p.second;
            if(dist[u] > dist[v] + w){
                dp2[u] = dp2[v] + 1;
                dp3[u] = dp3[v] + 1;
                dp1[u] = (dp1[v])%MOD;
                dist[u] = dist[v] + w;
                pq.push(make_pair(-dist[u], u));
            }else if(dist[u] == dist[v] + w){
                dp1[u] += dp1[v];
                dp1[u] %= MOD;
                dp2[u] = min(dp2[u], dp2[v] + 1);
                dp3[u] = max(dp3[u], dp3[v] + 1);
            }
        }
    }
    cout << dist[n] << ' ' << dp1[n] << ' ' << dp2[n] << ' ' << dp3[n] << endl;
    return 0;
}