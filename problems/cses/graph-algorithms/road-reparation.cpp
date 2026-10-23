#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
int n, m, lk[maxn], sz[maxn];
vector<tuple<ll, int, int>> edges;
int find(int a){
    while(a != lk[a])
        a = lk[a];
    return a;
}
bool same(int a, int b){
    return find(a) == find(b);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(sz[a] >= sz[b]) swap(a, b);
    sz[b] += sz[a];
    lk[a] = b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(w, a, b));
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; i++){
        lk[i] = i;
        sz[i] = 1;
    }
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
    for(int i = 2; i <= n ; i++)
        if(find(i) != find(1)){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    cout << ans << endl;
    return 0;
}