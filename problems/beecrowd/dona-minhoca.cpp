#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 50;
bool bridge[maxn][maxn];
vector<tuple<ll, int, int>> edges;
vector<pair<int, ll>> adj[maxn];
bool vis[maxn];
int tin[maxn], low[maxn], t = 0;
void dfs(int v, int dad){
    t++;
    tin[v] = t;
    low[v] = t;
    vis[v] = true;
    for(auto p : adj[v]){
        int u = p.first;
        if(!vis[u]){
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        }else{
            if(u == dad) continue;
            low[v] = min(low[v], tin[u]);
        }
    }
    if(v != 1 && low[v] == tin[v]){
        bridge[v][dad] = true;
        bridge[dad][v] = true;
    }
}

int lk[maxn], sz[maxn];
ll tam[maxn];
void set_dsu(int n){
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
ll dist;
int rs;
void dfs1(int x, int p, ll d){
    if(dist != 0)
        return;
    if(sz[find(x)] > 1){
        dist = d;
        rs = x;
        return;
    }
    for(auto e : adj[x]){
        int u = e.first;
        if(u == p)
            continue;
        dfs1(u, x, d + e.second);
    }
}
int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 1; i <= m; i++){
            int a, b;
            ll w;
            cin >> a >> b >> w;
            adj[a].push_back(make_pair(b, w));
            adj[b].push_back(make_pair(a, w));
            bridge[a][b] = false;
            bridge[b][a] = false;
            edges.push_back(make_tuple(w, a, b));
        }
        dfs(1, 0);
        set_dsu(n);
        for(auto e : edges){
            int a, b;
            ll w;
            tie(w, a, b) = e;
            if(bridge[a][b])
                continue;
            if(!same(a, b)){
                int pa = find(a), pb = find(b);
                unite(a, b);
                tam[find(a)] = tam[pa] + tam[pb] + w;
            }else
                tam[find(a)] += w;
        }
        for(int i = 1; i <= n; i++)
            cout << tam[find(i)] << endl;
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
            int s;
            ll tm;
            cin >> s >> tm;
            int ps = find(s);
            if(sz[ps] > 1){
                if(tm <= tam[ps])
                    cout << tam[ps] << endl;
                else
                    cout << -1 << endl;
            }else{
                dist = 0;
                dfs1(s, 0, 0);
                ps = find(rs);
                if(dist == 0 || tm > tam[ps])
                    cout << -1 << endl;
                else
                    cout << 2 * dist + tam[ps] << endl;
            }
        }
    }



    return 0;
}