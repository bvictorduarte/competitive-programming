#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int INF = 0x3f3f3f3f;
int n, m;
vector<int> adj[maxn];
int dist[maxn];
bool vis[maxn];
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : adj[v]) {
            if (vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[v]+1;
            q.push(u);
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
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(1);
        int cont_even = 0;
        for(int i = 1; i <= n; i++)
            if(!(dist[i] & 1))
                cont_even++;
        if(cont_even <= n/2){
            cout << cont_even << endl;
            for(int i = 1; i <= n; i++)
                if(!(dist[i] & 1))
                    cout << i << ' ';
        }else{
            cout << n - cont_even << endl;
            for(int i = 1; i <= n; i++)
                if(dist[i] & 1)
                    cout << i << ' ';
        }
        cout << endl;
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            vis[i] = false;
        }
    }

    return 0;
}