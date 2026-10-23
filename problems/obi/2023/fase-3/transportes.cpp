#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
map<int, vector<int>> adj[maxn];
map<int, ll> dist[maxn];
map<int, bool> vis[maxn];
set<int> colors[maxn];
ll p[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
        cin >> p[i];
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][c].push_back(b);
        colors[a].insert(c);
        adj[b][c].push_back(a);
        colors[b].insert(c);
    }
    int s, t;
    cin >> s >> t;
    for(int i = 1; i <= n; i++){
        dist[i][0] = LINF;
        for(auto color : colors[i])
            dist[i][color] = LINF;
    }
    priority_queue<tuple<ll, int, int>> pq;
    pq.push(make_tuple(0, s, 0));
    dist[s][0] = 0;
    while(!pq.empty()){
        int a = get<1>(pq.top()), c = get<2>(pq.top());
        pq.pop();
        if(vis[a][c]) continue;
        vis[a][c] = true;
        if(c == 0){
            for(auto color : colors[a]){
                for(auto u : adj[a][color]){
                    if(dist[u][color] > dist[a][c] + p[color]){
                        dist[u][color] = dist[a][c] + p[color];
                        pq.push(make_tuple(-dist[u][color], u, color));
                    }
                }
            }
        }else{
            if(dist[a][0] > dist[a][c]){
                dist[a][0] = dist[a][c];
                pq.push(make_tuple(-dist[a][0], a, 0));
            }
            for(auto u : adj[a][c])
                if(dist[u][c] > dist[a][c]){
                    dist[u][c] = dist[a][c];
                    pq.push(make_tuple(-dist[u][c], u, c));
                }
        }
    }
    if(!vis[t][0])
        cout << -1 << endl;
    else
        cout << dist[t][0] << endl;
    return 0;
}