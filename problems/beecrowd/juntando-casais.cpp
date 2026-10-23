#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
vector<int> adj[maxn][2], ord;
bool vis[maxn][2], in_cycle[maxn];
int comp[maxn], tam_comp[maxn], root[maxn], dp[30][maxn], dep[maxn], idx[maxn];
int c = 0, n;
void add_edge(int a, int b, bool directed){
    adj[a][0].push_back(b);
    adj[b][1].push_back(a);
    if(!directed){
        adj[b][0].push_back(a);
        adj[a][1].push_back(b);
    }
}
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
void make_trees(int x, int p, int r){
    root[x] = r;
    dp[0][x] = p;
    dep[x] = dep[p] + 1;
    for(auto u : adj[x][1]){
        if(u == p || in_cycle[u])
            continue;
        make_trees(u, x, r);
    }
}
void precompute(){
    for(int j = 1; j <= 25; j++)
        for(int i = 1; i <= n; i++)
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
}
int ancestor(int x, int k){
    for(int j = ceil(log2(maxn)) ; j >= 0; j--)
        if(k & (1 << j))
            x = dp[j][x];
    return x;
}
int lca(int a, int b){
    if(dep[a] < dep[b])
        swap(a,b);
    a = ancestor(a, dep[a]-dep[b]);
    if(a == b)
        return a;
    for(int i = ceil(log2(maxn)); i >= 0; i--)
        while(dp[i][a] != dp[i][b]){
            a = dp[i][a];
            b = dp[i][b];
        }
    return dp[0][a];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n){
        ord.resize(0);
        for(int i = 1; i <= n; i++){
            vis[i][0] = vis[i][1] = false;
            adj[i][0].resize(0);
            adj[i][1].resize(0);
            tam_comp[i] = 0;
            idx[i] = 0;
            comp[i] = 0;
            in_cycle[i] = false;
            root[i] = 0;
            dep[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            int a;
            cin >> a;
            add_edge(i, a, true);
        }
        kosarajus();
        for(int i = 1; i <= n; i++)
            tam_comp[comp[i]]++;
        for(int i = 1; i <= n; i++)
            if(tam_comp[comp[i]] > 1){
                in_cycle[i] = true;
                if(idx[i] == 0){
                    int cont = 0, it = i;
                    idx[i] = ++cont;
                    it = adj[i][0][0];
                    while(it != i){
                        idx[it] = ++cont;
                        it = adj[it][0][0];
                    }
                }
            }
        for(int i = 1; i <= n; i++)
            if(in_cycle[i])
                make_trees(i, i, i);
        precompute();
        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;
            if(comp[root[a]] != comp[root[b]])
                cout << -1 << endl;
            else{
                if(root[a] == root[b]){
                    int l = lca(a, b);
                    cout << dep[a] + dep[b] - 2 * dep[l] << endl;
                }else{
                    int ans = dep[a] + dep[b] - 2;
                    a = root[a];
                    b = root[b];
                    if(idx[b] < idx[a])
                        swap(a, b);
                    ans += min(idx[b] - idx[a], idx[a] + tam_comp[comp[a]] - idx[b]);
                    cout << ans << endl;
                }
            }
        }
    }


    return 0;
}