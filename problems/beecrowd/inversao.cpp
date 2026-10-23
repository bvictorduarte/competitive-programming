#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 3;
const int INF = 0x3f3f3f3f;
vector<int> adj[maxn];
int dp[6];
int dist[maxn];
bool vis[maxn];
void bfs(int s){
    queue<int> q;
    for(int i = 1; i <= maxn - 3; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}
int inv(int n){
    int tam = -1, aux = n;
    while(aux != 0){
        aux /= 10;
        tam++;
    }
    int j = tam;
    int ans = 0;
    for(int i = 1; i <= tam + 1; i++){
        ans += (n % 10) * dp[j];
        n /= 10;
        j--;
    }
    return ans;
}
void make_graph(){
    for(int i = 1; i <= maxn - 3; i++){
        int invi = inv(i);
        adj[i].push_back(invi);
        adj[i].push_back(i + 1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    dp[0] = 1;
    for(int i = 1; i <= 4; i++)
        dp[i] = dp[i - 1] * 10;
    make_graph();
    while(t--){
        int a, b;
        cin >> a >> b;
        bfs(a);
        cout << dist[b] << endl;
    }
    return 0;
}