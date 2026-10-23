#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
int c[maxn];
ll sz[maxn], ans[maxn];
vector<int> adj[maxn];
map<ll, ll> cst[maxn], freq[4 * maxn];
int mp[maxn];
ll v[maxn], st[4 * maxn];
ll tot;
void build(ll pos = 1, ll tl = 1, ll tr = tot){
    if(tl == tr){
        st[pos] = v[tl];
        swap(freq[pos], cst[mp[tl]]);
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*pos, tl, tm); build(2*pos+1, tm+1, tr);
    ll sum = 0;
    for(auto k : freq[2 * pos]){
        sum += freq[2 * pos][k.first] * freq[2 * pos + 1][k.first];
        freq[pos][k.first] += k.second;
    }
    for(auto k : freq[2 * pos + 1]){
        sum += freq[2 * pos][k.first] * freq[2 * pos + 1][k.first];
        freq[pos][k.first] += k.second;
    }
    st[pos] = st[2*pos] + st[2*pos+1] - 2 * sum;
}
void dfs(int x, int p){
    tot = (ll)adj[x].size();
    for(ll i = 1; i <= tot; i++){
        int u = adj[x][i - 1];
        if(u == p)
            continue;
        dfs(u, x);
        v[i] = ans[u];
        mp[i] = u;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    return 0;
}