#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 50;
int lk[maxn], sz[maxn];
int n;
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, ll>> adj[maxn];
vector<tuple<ll, int, int>> edges;
void set_dsu(){
    for(int i = 1; i <= n; i++){
        lk[i] = i;
        sz[i] = 1;
    }
}
int find(int x){
    while(x != lk[x])
        x = lk[x];
    return x;
}
bool same(int a, int b){
    return find(a) == find(b);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b])
        swap(a,b);
    sz[a] += sz[b];
    lk[b] = a;
}

int dp[maxn][30], dep[maxn];
ll dp2[maxn][30];
void dfs(int x = 1, int p = 0, ll w = LINF){
    dp[x][0] = p;
    dp2[x][0] = w;
    dep[x] = dep[p] + 1;
    for(auto edg : adj[x]){
        int u = edg.first, wu = edg.second;
        if(u != p)
            dfs(u, x, wu);
    }
}

void pre_compute(){
    for(int j = 1; j <= ceil(log2(maxn)); j++)
        for(int i = 1; i <= n; i++){
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
            dp2[i][j] = min(dp2[i][j - 1], dp2[dp[i][j - 1]][j - 1]);
        }
}

pair<int, ll> ancestor(int x, int k){
    ll ans = LINF;
    for(int j = ceil(log2(maxn)); j >= 0; j--)
        if(k & (1 << j)){
            ans = min(ans, dp2[x][j]);
            x = dp[x][j];
        }
    return make_pair(x, ans);
}

ll lca(int a,int b){
    ll ans = LINF;
    if(dep[a] < dep[b])
        swap(a, b);
    pair<int, ll> par;
    par = ancestor(a, dep[a]-dep[b]);
    a = par.first;
    ans = par.second;
    if(a == b)
        return ans;
    for(int i = ceil(log2(maxn)); i >= 0; i--)
        while(dp[a][i] != dp[b][i]){
            ans = min(ans, min(dp2[a][i], dp2[b][i]));
            a = dp[a][i];
            b = dp[b][i];
        }
    return min(ans, min(dp2[a][0], dp2[b][0]));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, s;
    while(cin >> n >> m >> s){
        edges.resize(0);
        for(int i = 1; i <= n; i++)
            adj[i].resize(0);
        dep[1] = 0;
        for(int i = 1; i <= m; i++){
            int a, b;
            ll w;
            cin >> a >> b >> w;
            edges.push_back(make_tuple(w, a, b));
        }
        set_dsu();
        sort(edges.rbegin(), edges.rend());
        for(auto edg : edges){
            int a, b;
            ll w;
            tie(w, a, b) = edg;
            if(!same(a, b)){
                unite(a, b);
                adj[a].push_back(make_pair(b, w));
                adj[b].push_back(make_pair(a, w));
            }
        }
        dfs();
        pre_compute();
        for(int i = 1; i <= s; i++){
            int a, b;
            cin >> a >> b;
            cout << lca(a, b) << endl;
        }
    }

    return 0;
}