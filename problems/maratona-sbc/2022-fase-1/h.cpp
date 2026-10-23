#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 50;
vector<int> adj[maxn][2], ord;
vector<pair<int, int>> edges;
bool vis[maxn][2], cvis[maxn];
int c = 0, comp[maxn], n;
bool idg[maxn], odg[maxn];
set<int> cadj[maxn];
void add_edge(int a, int b, bool directed = true){
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
int cdfs(int x, int root){
    cvis[x] = true;
    if(cadj[x].empty())
        return 1;
    int ans = 0;
    for(auto u : cadj[x]){
        if(cvis[u])
            continue;
        ans += cdfs(u, root);
    }
    if(ans == 0)
        return 1;
    return ans;
}
void kosarajus(){
    for(int i = 1; i <= n; i++)
            if(!vis[i][0])
                dfs(i, 0);
    reverse(ord.begin(), ord.end());
    c = 0;
    for(auto u : ord)
        if(!vis[u][1]){
            c++;
            dfs(u, 1);
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        edges.push_back(make_pair(a, b));
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    } 
    kosarajus();
    if(c == 1){
        cout << 0 << endl;
        return 0;
    }
    for(auto e : edges){
        int a, b;
        tie(a, b) = e;
        if(comp[a] != comp[b]){
            cadj[comp[a]].insert(comp[b]);
            idg[comp[b]] = true;
            odg[comp[a]] = true;
        }
    }
    int ans = 0, ci = 0, co = 0;
    for(int i = 1; i <= c; i++){
        if(!idg[i])
            ci++;
        if(!odg[i])
            co++;
    }
    ans = max(ci, co);
    cout << ans << endl;
    return 0;
}