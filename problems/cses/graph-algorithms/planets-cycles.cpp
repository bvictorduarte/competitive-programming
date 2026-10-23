#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
vector<int> adj[maxn][2], ord;
bool vis[maxn][2];
int c = 0, comp[maxn], dp[maxn][21], n, tam_comp[maxn];
void dfs(int x, int op){
    vis[x][op] = true;
    if(op){
        comp[x] = c;
        tam_comp[c]++;
    }
    for(auto u : adj[x][op])
        if(!vis[u][op])
            dfs(u, op);
    if(!op)
        ord.push_back(x);
}
void precompute(){
    for(int j = 1; j <= 20; j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}
pair<int, int> dist(int a){
    int ans = 0;
    if(comp[a] == comp[dp[a][0]])
        return make_pair(ans, a);
    for(int j = 20; j >= 0; j--)
        while(comp[dp[a][j]] != comp[dp[dp[a][j]][0]]){
            a = dp[a][j];
            ans += (1<<j);
        }
    return make_pair(++ans, dp[a][0]);
}
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        adj[i][0].push_back(a);
        dp[i][0] = a;
        adj[a][1].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i][0])
            dfs(i, 0);
    reverse(ord.begin(), ord.end());
    for(auto u : ord)
        if(!vis[u][1]){
            c++;
            dfs(u, 1);
        }
    precompute();
    for(int i = 1; i <= n; i++){
        pair<int, int> p = dist(i);
        cout << p.first + tam_comp[comp[p.second]] << ' ';
    }
    cout << endl;
    return 0;
}