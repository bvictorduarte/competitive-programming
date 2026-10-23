#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
ll dist[maxn][2];
vector<tuple<int, int, ll>> adj[maxn][2];
bool vis[maxn][2];
int n, m;
void dijkstra(int s){
    priority_queue<tuple<ll, int, int>> pq;
    for(int i = 1; i <= n; i++){
        dist[i][0] = LINF;
        dist[i][1] = LINF;
    }
    dist[s][0] = 0;
    pq.push(make_tuple(0, s, 0));
    while(!pq.empty()){
        int a = get<1>(pq.top()), op = get<2>(pq.top());
        pq.pop();
        if (vis[a][op]) continue;
        vis[a][op] = true;
        for(auto u : adj[a][op]){
            int b, opb;
            ll w;
            tie(b, opb, w) = u;
            if(dist[a][op] + w < dist[b][opb]){
                dist[b][opb] = dist[a][op] + w;
                pq.push(make_tuple(-dist[b][opb], b, opb));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        adj[i][0].push_back(make_tuple(i, 1, 0));
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a][0].push_back(make_tuple(b, 0, w));
        adj[b][1].push_back(make_tuple(a, 1, w));
    }
    dijkstra(1);
    for(int i = 2; i <= n; i++)
        if(dist[i][1] != LINF)
            cout << dist[i][1] << ' ';
        else
            cout << -1 << ' ';
    cout << endl;
    return 0;
}