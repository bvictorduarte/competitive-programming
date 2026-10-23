#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 50;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
ll v[maxn], dp[maxn][20];
void dfs(int x, int p){
    for(int i = 1; i <= 19; i++)
        dp[x][i] = v[x] * i;
    for(auto u : adj[x]){
        if(u == p)
            continue;
        dfs(u, x);
        ll aux[20];
        for(int i = 1; i <= 19; i++)
            aux[i] = LINF;
        for(int i = 1; i <= 19; i++)
            for(int k = 1; k <= 19; k++)
                if(i != k)
                    aux[i] = min(aux[i], dp[u][k]);
        for(int i = 1; i <= 19; i++)
            dp[x][i] += aux[i];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            adj[i].resize(0);
        }
        for(int i = 1; i <= n - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        ll ans = dp[1][1];
        for(int i = 2; i <= 19; i++)
            ans = min(ans, dp[1][i]);
        cout << ans << endl;
    }
}