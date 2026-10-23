#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 50;
bool adj_matrix[maxn][maxn];
ll dist[maxn], dist_s[maxn], dist_t[maxn];
vector<pair<int, ll>> adj[maxn];
bool vis[maxn];
int n;
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
    int m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(make_pair(b, 1));
        adj[b].push_back(make_pair(a, 1));
        adj_matrix[a][b] = true;
        adj_matrix[b][a] = true;
    }
    dijkstra(s);
    for(int i = 1; i <= n; i++)
        dist_s[i] = dist[i];
    dijkstra(t);
    for(int i = 1; i <= n; i++)
        dist_t[i] = dist[i];
    int cont = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(!adj_matrix[i][j] && dist_s[i] + dist_t[j] + 1 >= dist_s[t] && dist_s[j] + dist_t[i] + 1 >= dist_s[t])
                cont++;
    cout << cont << endl;
    return 0;
}