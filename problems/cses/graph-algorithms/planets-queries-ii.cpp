#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int n, c = 0, comp[maxn], posi[maxn], dp[maxn][21], tam_comp[maxn];
vector<int> adj[maxn][2], ord;
bool vis[maxn][2];
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
    else{
        
    }
}
void precompute(){
    for(int j = 1; j <= 20; j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}
pair<int, int> dist(int a, int b){
    int ans = 0;
    if(comp[b] < comp[a])
        return make_pair(-1, dp[a][0]);
    if(comp[a] == comp[b])
        return make_pair(ans, a);
    for(int j = 20; j >= 0; j--)
        while(comp[dp[a][j]] < comp[b] && ans <= n + 4){
            ans += (1<<j);
            a = dp[a][j];
        }
    if(comp[dp[a][0]] != comp[b])
        return make_pair(-1, a);
    return make_pair(++ans, dp[a][0]);
}
bool possible(int a, int b){
    for(int j = 0; j <= 20; j++)
        if(n & (1 << j))
            a = dp[a][j];
    return comp[a] == comp[b];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        dp[i][0] = a;
        adj[i][0].push_back(a);
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
    int cur = 0, p = 0;
    for(auto u : ord){
        if(comp[u] != cur){
            cur++;
            p = 1;
        }else
            p++;
        posi[u] = p;
    }
    precompute();
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        pair<int, int> p = dist(a, b);
        if(p.first == -1)
            cout << -1 << endl;
        else{
            if(posi[p.second] <= posi[b])
                cout << p.first + posi[b] - posi[p.second] << endl;
            else
                cout << p.first - posi[p.second] + tam_comp[comp[b]] + posi[b] << endl;
        }
    }
    return 0;
}