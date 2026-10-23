#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 50;
vector<int> adj[maxn];
int n;
int dp[maxn], tam_sub[maxn];
void dfs(int x, int p){
    dp[x] = 0;
    tam_sub[x] = 1;
    for(auto u : adj[x])
        if(u != p){
            dfs(u, x);
            tam_sub[x] += tam_sub[u];
        }
    for(auto u : adj[x])
        if(u != p && (((int)adj[x].size() == 3 && x != 1) || ((int)adj[x].size() == 2 && x == 1)))
            dp[x] = max(dp[x], tam_sub[x] - tam_sub[u] - 2 + dp[u]);
        else if( u != p)
            dp[x] = tam_sub[x] - 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            dp[i] = 0;
        }
        for(int i = 1; i <= n - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        cout << dp[1] << endl;
    }
    return 0;
}