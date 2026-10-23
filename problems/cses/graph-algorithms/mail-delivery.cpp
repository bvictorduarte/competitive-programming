#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
vector<pair<int, int>> adj[maxn];
int even_degree = 0, n, m;
bool vis[maxn];
vector<int> path;
void dfs(int x = 1){
    while(!adj[x].empty()){
        int viz = adj[x].back().first, idx = adj[x].back().second;
        adj[x].pop_back();
        if(!vis[idx]){
            vis[idx] = true;
            dfs(viz);
        }
    }
    path.push_back(x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(make_pair(b, i));
        adj[b].push_back(make_pair(a, i));
    }
    for(int i = 1; i <= n; i++)
        if((int)adj[i].size() % 2 == 0)
            even_degree++;
    if(even_degree != n)
        cout << "IMPOSSIBLE\n";
    else{
        dfs();
        if((int)path.size() != m + 1)
            cout << "IMPOSSIBLE";
        else
            for(auto u : path)
                cout << u << ' ';
        cout << '\n';
    }
    return 0;   
}