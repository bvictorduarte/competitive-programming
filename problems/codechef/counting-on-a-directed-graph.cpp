#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 50;
vector<int> adj[maxn], dom_tree[maxn], rg[maxn], bucket[maxn];
int dsu[maxn], label[maxn], sdom[maxn], arr[maxn], t = 0, rev[maxn], par[maxn], dom[maxn];
ll dp[maxn];

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
    dp[v] = 1;
    for(auto u : dom_tree[v])
        if(u != dad){
            dfs1(u, v);
            dp[v] += dp[u];
        }
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
    dfs1();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    build_dom_tree();
    ll ans = 0;
    for(auto u : dom_tree[1])
        ans += dp[u] * (dp[1] - 1LL - dp[u]);
    ans += 2LL * (dp[1] - 1LL);
    cout << ans / 2 << endl;
    return 0;
}