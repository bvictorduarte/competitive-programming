#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
ll dist[maxn];
vector<pair<int, ll>> adj[maxn];
bool vis[maxn];
void dijkstra(int s, int n){
    priority_queue<pair<ll, int>> pq;
    for(int i = 0; i <= n + 1; i++)
        dist[i] = LINF;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if (vis[a]) continue;
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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        s.push_back('a');
        string aux;
        cin >> aux;
        s = s + aux;
        for(int i = 0; i <= n + 1; i++){
            adj[i].resize(0);
            vis[i] = false;
        }
        for(int i = 1; i <= m; i++)
            adj[0].push_back(make_pair(i, 0));
        for(int i = 1; i <= n; i++){
            if(s[i] == 'L')
                for(int j = 1; j <= m; j++)
                    adj[i].push_back(make_pair(i + j, 0));
            if(s[i] == 'W')
                adj[i].push_back(make_pair(i + 1, 1));
        }
        dijkstra(0, n);
        if(dist[n + 1] <= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}