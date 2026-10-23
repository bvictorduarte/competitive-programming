#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 50;
int pre[maxn];
bool vis[maxn];
vector<pair<int, ll>> adj[maxn];
ll dist[maxn];
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    priority_queue<pair<ll, int>>  pq;
    pre[1] = 1;
    pq.push(make_pair(0, 1));
    for(int i = 2; i <= n; i++)
        dist[i] = LINF;
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
    if(dist[n] == LINF){
        cout << -1 << endl;
        return 0;
    }
    int it = n;
    vector<int> ans;
    while(it != pre[it]){
        ans.push_back(it);
        it = pre[it];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u << ' ';
    cout << endl;
    return 0;
}