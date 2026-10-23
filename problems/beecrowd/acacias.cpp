#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 50;
typedef long long ll;
vector<tuple<ll, int, int>> edges;
int lk[maxn], sz[maxn];
bool root[maxn];
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set_dsu(n);
    for(int a = 1; a <= n - 1; a++){
        int quant;
        cin >> quant;
        for(int i = 1; i <= quant; i++){
            int b;
            ll w;
            cin >> b >> w;
            edges.push_back(make_tuple(w, a, b));
        }
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for(auto e : edges){
        int a, b;
        ll w;
        tie(w, a, b) = e;
        if(!same(a, b)){
            unite(a, b);
            ans += w;
        }
    }
    int cont = 0;
    for(int i = 1; i <= n; i++){
        int dad = find(i);
        if(!root[dad]){
            cont++;
            root[dad] = true;
        }
    }
    cout << cont << ' ' << ans << endl;
    return 0;
}