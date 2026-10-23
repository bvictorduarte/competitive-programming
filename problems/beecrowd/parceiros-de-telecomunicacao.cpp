#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int maxn = 1e3 + 50;
ordered_set comp[maxn];
int n, m, k, cont;
int deg[maxn], ans[maxn];
bool vis[maxn], mark[maxn];
vector<int> adj[maxn];
void dfs(int v){
    if(vis[v] || !mark[v])
        return;
    vis[v] = true;
    comp[cont].insert(make_pair(deg[v], v));
    for(auto u : adj[v])
        dfs(u);
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m >> k && n){
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            deg[i] = 0;
            mark[i] = true;
            vis[i] = false;
        }
        for(int i = 1; i <= cont; i++){
            ans[i] = 0;
            comp[i].clear();
        }
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        cont = 0;
        for(int i = 1; i <= n; i++)
            if(!vis[i]){
                cont++;
                dfs(i);
            }
        for(int i = 1; i <= cont; i++){
            int tam;
            tam = ans[i] = (int)comp[i].size();
            for(int j = 0; j < tam; j++){
                pair<int, int> p = *(comp[i].find_by_order(j));
                int v = p.second;
                comp[i].erase(comp[i].find_by_order(j));
                comp[i].insert(make_pair(-1, v));
                if(deg[v] < k){
                    mark[v] = false;
                    ans[i]--;
                    for(auto u : adj[v]){
                        if(!mark[u])
                            continue;
                        else{
                            comp[i].erase(comp[i].find(make_pair(deg[u], u)));
                            deg[u]--;
                            comp[i].insert(make_pair(deg[u], u));
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= cont; i++){
            ans[i] = 0;
            comp[i].clear();
        }
        for(int i = 1; i <= n; i++)
            vis[i] = false;
        for(int i = 1; i <= n; i++)
            if(!vis[i]){
                cont++;
                dfs(i);
            }
        int resp = -1;
        for(int i = 1; i <= cont; i++)
            resp = max(resp, (int)comp[i].size());
        cout << resp << endl;
    }
    return 0;
}