#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
vector<int> adj[maxn][2], ord;
vector<int> kadj[maxn];
vector<tuple<int, int>> edges;
bool vis[maxn][2];
int c = 0, n;
int dp[maxn], comp[maxn];
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    while(cin >> n >> m){
        int s, t;
        for(int i = 1; i <= n; i++){
            adj[i][0].resize(0);
            vis[i][0] = false;
            vis[i][1] = false;
            adj[i][1].resize(0);
            kadj[i].resize(0);
            comp[i] = 0;
            dp[i] = 0;
        }
        ord.resize(0);
        edges.resize(0);
        for(int i = 1; i <= m; i++){
            int a, b, op;
            cin >> a >> b >> op;
            if(i == 1){
                s = a;
                t = b;
                continue;
            }
            edges.push_back(make_tuple(a, b));
            if(op == 2)
                add_edge(a, b, false);
            else
                add_edge(a, b, true);
        }
        kosarajus();
        if(comp[s] == comp[t])
            cout << '-';
        else{
            for(int v = 1; v <= n; v++)
                for(auto u : adj[v][0]){
                    if(comp[v] == comp[u])
                        continue;
                    kadj[comp[u]].push_back(comp[v]);
                }
            if(comp[s] > comp[t])
                swap(s, t);
            dp[comp[s]] = 1;
            for(int i = comp[s] + 1; i <= comp[t]; i++)
                for(auto u : kadj[i])
                    dp[i] += dp[u];
            if(dp[comp[t]] > 1)
                cout << '1';
            else if(dp[comp[t]] == 1)
                cout << '2';
            else
                cout << '*';
        }
        cout << '\n';
    }
    return 0;
}