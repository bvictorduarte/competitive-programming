#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5 + 50;
int pre[maxn];
bool vis[maxn];
vector<pair<int, ll>> adj[maxn];
ll dist[maxn];
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }
    priority_queue<pair<ll, int>>  pq;
    pre[s] = -1;
    pq.push(make_pair(0, s));
    for(int i = 0; i < n; i++)
        dist[i] = LINF;
    dist[s] = 0;
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        if(vis[v]) continue;
        vis[v] = true;
        for(auto e : adj[v]){
            int u = e.first;
            ll w = e.second;
            if(dist[u] > dist[v] + w){
                pre[u] = v;
                dist[u] = dist[v] + w;
                pq.push(make_pair(-dist[u], u));
            }
        }
    }
    if(dist[t] == LINF){
        cout << -1 << endl;
        return 0;
    }
    cout << dist[t] << ' ';
    int it = t;
    vector<int> ans;
    while(it != -1){
        ans.push_back(it);
        it = pre[it];
    }
    cout << (int)ans.size() - 1 << endl;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size() - 1; i++)
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    return 0;
}