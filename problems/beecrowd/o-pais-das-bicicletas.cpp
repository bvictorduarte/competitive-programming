#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
int lk[maxn], sz[maxn], dad[maxn], dep[maxn], wd[maxn];
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> adj[maxn];
int n;
const int INF = 0x3f3f3f3f;
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
void dfs(int v, int p, int w){
    wd[v] = w;
    dad[v] = p;
    dep[v] = dep[p] + 1;
    for(auto e : adj[v]){
        int u = e.first, we = e.second;
        if(u == p)
            continue;
        dfs(u, v, we);
    }
}
int main(){
    int m, cont = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m && !(!n && !m)){
        edges.resize(0);
        for(int i = 1; i <= n; i++)
            adj[i].resize(0);
        for(int i = 1; i <= m; i++){
            int a, b, w;
            cin >> a >> b >> w;
            edges.push_back(make_tuple(w, a, b));
        }
        sort(edges.begin(), edges.end());
        set_dsu();
        for(auto e : edges){
            int a, b, w;
            tie(w, a, b) = e;
            if(!same(a, b)){
                unite(a, b);
                adj[a].push_back(make_pair(b, w));
                adj[b].push_back(make_pair(a, w));
            }
        }
        dfs(1, 0, 0);
        int k;
        cin >> k;
        cout << "Instancia " << ++cont << endl;
        for(int i = 1; i <= k; i++){
            int s, t;
            cin >> s >> t;
            if(s == t){
                cout << 0 << endl;
                continue;
            }
            if(dep[s] < dep[t])
                swap(s, t);
            int is = s, it = t, ans = -INF;
            while(dep[is] > dep[t]){
                ans = max(ans, wd[is]);
                is = dad[is];
            }
            while(is != it){
                ans = max(ans, max(wd[is], wd[it]));
                is = dad[is];
                it = dad[it];
            }
            cout << ans << endl;
        }
        cout << endl;
    }
}