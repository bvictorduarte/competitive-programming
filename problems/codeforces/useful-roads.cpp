#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
vector<int> adj[maxn], dom_tree[maxn], rg[maxn], bucket[maxn];
int dsu[maxn], label[maxn], sdom[maxn], arr[maxn], t = 0, rev[maxn], par[maxn], dom[maxn], n, m, dp[maxn][22], dep[maxn];
pair<int, int> edges[maxn];
int find(int u, int x = 0){
    if(u == dsu[u]) return x ? -1 : u;
    int v = find(dsu[u], x + 1);
    if(v < 0) return u;
    if(sdom[label[dsu[u]]] < sdom[label[u]])
        label[u] = label[dsu[u]];
    dsu[u] = v;
    return x ? v : label[u];
}

void unite(int u, int v){
    dsu[v] = u;
}

void dfs0(int u){
    t++;
    arr[u] = t;
    rev[t] = u;
    label[t] = t;
    sdom[t] = t;
    dsu[t] = t;
    for(auto w : adj[u]){
        if(!arr[w]){
            dfs0(w);
            par[arr[w]] = arr[u];
        }
        rg[arr[w]].push_back(arr[u]);
    }
}

void dfs1(int v = 1, int dad = 0){
    dom[v] = dad;
    dp[v][0] = dad;
    dep[v] = dep[dad] + 1;
    for(auto u : dom_tree[v])
        if(u != dad)
            dfs1(u, v);
}

void build_dom_tree(){
    dfs0(1);
    for(int i = t; i >= 1; i--){
        for(int j = 0; j < (int)rg[i].size(); j++)
            sdom[i] = min(sdom[i], sdom[find(rg[i][j])]);
        if(i > 1)
            bucket[sdom[i]].push_back(i);
        for(auto w : bucket[i]){
            int v = find(w);
            if(sdom[v] == sdom[w])
                dom[w] = sdom[w];
            else
                dom[w] = v;
        }
        if(i > 1)
            unite(par[i], i);
    }
    for(int i = 2; i <= t; i++){
        if(dom[i] != sdom[i])
            dom[i] = dom[dom[i]];
        dom_tree[rev[i]].push_back(rev[dom[i]]);
        dom_tree[rev[dom[i]]].push_back(rev[i]);
    }
    dfs1(); //seta corretamente dom[i]
}
void reset(){
    for(int i = 1; i <= n; i++){
        t = 0;
        dom_tree[i].resize(0);
        adj[i].resize(0);
        rg[i].resize(0);
        bucket[i].resize(0);
        dsu[i] = 0;
        label[i] = 0;
        sdom[i] = 0;
        arr[i] = 0;
        rev[i] = 0;
        par[i] = 0;
        dom[i] = 0;
        dep[i] = 0;
        for(int j = 0; j <= ceil(log2(n)); j++)
            dp[i][j] = 0;
    }
}
void precompute(){
    for(int j = 1; j <= ceil(log2(n)); j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}
int b_jump(int a, int k){
    for(int j = 0; j <= ceil(log2(n)); j++)
        if((1 << j) & k)
            a = dp[a][j];
    return a;
}
int lca(int a, int b){
    if(dep[a] < dep[b])
        swap(a, b);
    a = b_jump(a, dep[a] - dep[b]);
    if(a == b)
        return a;
    for(int j = ceil(log2(n)); j >= 0; j--)
        while(dp[a][j] != dp[b][j]){
            a = dp[a][j];
            b = dp[b][j];
        }
    return dp[a][0];
}
int main(){
    while(cin >> n >> m){
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            edges[i] = make_pair(a, b);
        }
        build_dom_tree();
        precompute();
        vector<int> ans;
        for(int i = 1; i <= m; i++){
            int a, b;
            tie(a, b) = edges[i];
            if(dep[a] && dep[b] && lca(a, b) != b)
                ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        cout << (int)ans.size() << endl;
        if(!ans.empty())
            cout << ans[0];
        for(int i = 1; i < (int)ans.size(); i++)
            cout << ' ' << ans[i];
        cout << endl;
        reset();
    }
    return 0;
}