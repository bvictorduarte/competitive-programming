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