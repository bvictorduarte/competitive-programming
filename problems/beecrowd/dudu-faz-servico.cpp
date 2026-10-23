#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 50;
set<int> adj[maxn];
int vis[maxn];
bool has = false;
void dfs(int v){
    if(vis[v] == 1){
        has = true;
        return;
    }
    if(vis[v] == 2)
        return;
    vis[v] = 1;
    for(auto u : adj[v])
        dfs(u);
    vis[v] = 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        has = false;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            if(a == b)
                has = true;
            adj[a].insert(b);
        }
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i);
        if(has)
            cout << "SIM\n";
        else
            cout << "NAO\n";
    }
    return 0;
}