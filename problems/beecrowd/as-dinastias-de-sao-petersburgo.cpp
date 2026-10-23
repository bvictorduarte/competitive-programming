#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
int n, k;
vector<int> adj[maxn];
int mt[maxn];
bool used[maxn];
bool try_kuhn(int v){
    if(used[v])
        return false;
    used[v] = true;
    for(int u : adj[v]){
        if(mt[u] == -1 || try_kuhn(mt[u])){
            mt[u] = v;
            return true;
        }
    }
    return false;
}
int MBM(){
    for(int i = 1; i <= k; i++)
        mt[i] = -1;
    int tam = 0;
    for(int v = 1; v <= n; v++){
        for(int i = 1; i <= n; i++)
            used[i] = false;
        if(try_kuhn(v))
            tam++;
    }
    return tam;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    while(cin >> n >> m){
        k = n;
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        cout << n - MBM() << endl;
        for(int i = 1; i <= n; i++)
            adj[i].resize(0);
    }
    return 0;
}