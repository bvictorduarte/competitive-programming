#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
vector<int> adj[maxn][2], ord;
bool vis[maxn][2];
int c = 0, comp[maxn];
void dfs(int x, int op){
    vis[x][op] = true;
    if(op)
        comp[x] = c;
    for(auto u : adj[x][op])
        if(!vis[u][op])
            dfs(u, op);
    if(!op)
        ord.push_back(x);
}
int main(){
    int n, m;
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i][0])
            dfs(i, 0);
    reverse(ord.rbegin(),ord.rend());
    for(auto u : ord)
        if(!vis[u][1]){
            c++;
            dfs(u, 1);
        }
    cout << c << endl;
    for(int i = 1; i <= n; i++)
        cout << comp[i] << ' ';
    cout << '\n';
    return 0;
}