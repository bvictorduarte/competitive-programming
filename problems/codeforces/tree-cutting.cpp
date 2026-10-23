#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int n, k, curk;
vector<int> adj[maxn];
int dfs(int v, int p, int x){
    int tam = 1;
    for(auto u : adj[v])
        if(u != p)
            tam += dfs(u, v, x);
    if(tam >= x && curk > 0){
        tam = 0;
        curk--;
    }
    return tam;
}
bool valid(int x){
    curk = k;
    return dfs(1, 0, x) >= x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            adj[i].resize(0);
        for(int i = 1; i <= n - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int x = 1;
        for(int b = maxn; b >= 1; b /= 2)
            while(valid(x + b)) 
                x += b;
        cout << x << endl;
    }
    return 0;
}