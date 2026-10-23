#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
#define l(p) p<<1
#define r(p) (p<<1) + 1
int n, parent[maxn], dep[maxn], heavy[maxn], head[maxn], t = 1, posi[maxn], st[4 * maxn], lazy[4 * maxn];
vector<int> adj[maxn];
void propagate(int p, int L, int R){
    if(lazy[p]){
        st[p] += lazy[p] * (R - L + 1);
        if(L != R){
            lazy[l(p)] += lazy[p];
            lazy[r(p)] += lazy[p];
        }
        lazy[p] = 0;
    }
}
int RSQ(int i, int j, int p = 1, int L = 1, int R = n){
    propagate(p, L, R);
    if(i > R || j < L) return 0;
    if(i <= L && R <= j) return st[p];
    int m = (L + R) / 2;
    return RSQ(i, j, l(p), L, m) + RSQ(i, j, r(p), m+1, R);
}
void update(int i, int j, int val, int p = 1, int L = 1, int R = n){
    propagate(p, L, R);
    if(i > R || j < L) return;
    if(i <= L && R <= j){
        lazy[p] += val;
        propagate(p, L, R);
    }else{
        int m = (R + L) / 2;
        update(i, j, val, l(p), L, m);
        update(i, j, val, r(p), m+1, R);
        st[p] = st[l(p)] + st[r(p)];
    }
}
int dfs(int x = 1, int p = 1){
    int sz = 1;
    int max_sz_u = 0;
    parent[x] = p;
    dep[x] = dep[p] + 1;
    for(auto u : adj[x])
        if(u != p){
            int sz_u = dfs(u, x);
            sz += sz_u;
            if(sz_u > max_sz_u){
                heavy[x] = u;
                max_sz_u = sz_u;
            }
        }
    return sz;
}
void decompose(int x = 1, int h = 1){
    head[x] = h;
    posi[x] = t++;
    if(heavy[x])
        decompose(heavy[x], h);
    for(auto u : adj[x])
        if(u != parent[x] && u != heavy[x])
            decompose(u, u);
}
void sum_tree(int a, int b, int val){
    while(head[a] != head[b]){
        if(dep[head[a]] < dep[head[b]]) swap(a, b);
        update(posi[head[a]], posi[a], val);
        a = parent[head[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    update(posi[b], posi[a], val);
}
int query(int a, int b){
    int sum = 0;
    while(head[a] != head[b]){
        if(dep[head[a]] < dep[head[b]]) swap(a, b);
        sum += RSQ(posi[head[a]], posi[a]);
        a = parent[head[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    sum += RSQ(posi[b], posi[a]);
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    decompose();
    for(int i = 1; i <= q; i++){
        int a, b, c, d;
        cin >> a>> b >> c >> d;
        sum_tree(a, b, 1);
        int tam = query(a, b);
        sum_tree(c, d, -1);
        cout << tam - query(a, b) << endl;
        sum_tree(a, b, -1);
        sum_tree(c, d, 1);
    }
    return 0;
}