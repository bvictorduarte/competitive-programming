#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 50;
vector<int> adj[maxn][2], ord;
bool vis[maxn][2];
int c = 0, comp[maxn], n;
void dfs(int x, int f){
    vis[x][f] = true;
    if(f)
        comp[x] = c;
    for(auto u : adj[x][f])
        if(!vis[u][f])
            dfs(u, f);
    if(!f)
        ord.push_back(x);
}
void kosarajus(){
    for(int i = 1; i <= n; i++)
            if(!vis[i][0])
                dfs(i, 0);
    reverse(ord.begin(),ord.end());
    c = 0;
    for(auto u : ord)
        if(!vis[u][1]){
            c++;
            dfs(u, 1);
        }
}
void add_edge(int a, int b, bool directed){
    adj[a][0].push_back(b);
    adj[b][1].push_back(a);
    if(!directed){
        adj[b][0].push_back(a);
        adj[a][1].push_back(b);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    while(cin >> n >> m && n && m){
        for(int i = 1; i <= m; i++){
            int a, b, op;
            cin >> a >> b >> op;
            if(op == 2)
                add_edge(a, b, 0);
            else
                add_edge(a, b, 1);
        }
        kosarajus();
        if(c == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        for(int i = 1; i <= n; i++){
            adj[i][0].resize(0);
            adj[i][1].resize(0);
            vis[i][0] = vis[i][1] = false;
        }
        ord.resize(0);
    }
}