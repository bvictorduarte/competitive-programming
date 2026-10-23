#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
ll dist[maxn];
vector<pair<int, ll>> adj[maxn];
bool vis[maxn];
int n;
void dijkstra(int s){
    priority_queue<pair<ll, int>> pq;
    for(int i = 1; i <= n; i++)
        dist[i] = LINF;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    for(int i = 1; i <= n - 1; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
        sum += w;
    }
    sum *= 2;
    dijkstra(1);
    ll min_leaf = -1;
    for(int i = 2; i <= n; i++)
        if((int)adj[i].size() == 1)
            min_leaf = max(min_leaf, dist[i]);
    cout << sum - min_leaf << endl;
    return 0;
}