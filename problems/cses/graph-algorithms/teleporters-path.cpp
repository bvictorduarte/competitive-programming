#include<bits/stdc++.h>
using namespace std;
const int maxm = 2e5 + 50;
const int maxn = 1e5 + 50;
int n, m, in_degree[maxn], out_degree[maxn], cont = 0;
bool vis[maxm];
vector<pair<int, int>> adj[maxn];
vector<int> path;
void dfs(int x = 1){
    while(!adj[x].empty()){
        int viz = adj[x].back().first, idx = adj[x].back().second;
        adj[x].pop_back();
        if(vis[idx])continue;
        vis[idx] = true;
        dfs(viz);
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
        in_degree[b]++;
        out_degree[a]++;
    }
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++)
        if(in_degree[i] == out_degree[i])
            cont++;
        else if(in_degree[i] - out_degree[i] == 1)
            b = i;
        else if(out_degree[i] - in_degree[i] == 1)
            a = i;
    if(!(cont == n - 2 && a == 1 && b == n)){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs();
    reverse(path.begin(), path.end());
    if((int)path.size() != m + 1)
        cout << "IMPOSSIBLE\n";
    else{
        for(int i = 0; i < m + 1; i++)
            cout << path[i] << ' ';
        cout << '\n';
    }
    return 0;
}