#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
int v[maxn], mult[] = {-1, 1}, n;
int dist[maxn][2];
bool vis[maxn][2];
vector<int> adj[maxn];
bool valid(int x){
    return x <= n && x >= 1;
}
void bfs(int f){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        dist[i][f] = INF;
    for(int i = 1; i <= n; i++)
        if((!f && v[i] & 1) || (f && !(v[i] & 1))){
            dist[i][f] = 0;
            vis[i][f] = true;
            q.push(i);
        }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for (auto u : adj[v]) {
            if(vis[u][f])
                continue;
            vis[u][f] = true;
            dist[u][f] = dist[v][f] + 1;
            q.push(u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        for(int j = 0; j < 2; j++){
            if(!valid(i + mult[j] * v[i]))
                continue;
            adj[i + mult[j] * v[i]].push_back(i);
        }
    }
    bfs(0);
    bfs(1);
    for(int i = 1; i <= n; i++)
        if(v[i] & 1){
            if(dist[i][1] != INF)
                cout << dist[i][1] << ' ';
            else
                cout << -1 << ' ';
        }
        else{
            if(dist[i][0] != INF)
                cout << dist[i][0] << ' ';
            else
                cout << -1 << ' ';
        }
    cout << '\n';
    return 0;
}