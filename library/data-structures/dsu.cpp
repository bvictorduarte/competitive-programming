int lk[maxn], sz[maxn];
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