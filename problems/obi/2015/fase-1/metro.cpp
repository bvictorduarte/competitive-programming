#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 50;
vector<int> adj[maxn];
bool vis[maxn];
int d[maxn], t, s, deg[maxn], ini;
void dfs(int x, int p = 0 ){
    if(t != -1)
        return;
    vis[x] = true;
    d[x] = p;
    for(auto u : adj[x]){
        if( t != -1)
            return;
        if(u != p){
            if(!vis[u]){
                dfs(u, x);
            }else if(u != ini){
                s = x;
                t = u;
                return;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] >= 5){
            ini = i;
            break;
        }
    t = -1;
    dfs(ini);
    int cur = s, cont = 0;
    while(cur != t){
        cont ++;
        cur = d[cur];
    }
    cout << cont + 1 << endl;
    return 0;
}