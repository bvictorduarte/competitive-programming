#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int cont[maxn];
typedef long long ll;
vector<pair<int, ll>> adj[maxn];
vector<ll> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }
    priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0, 1));
    while(cont[n] < k){
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if(cont[u] == k)continue;
        cont[u]++;
        if(u==n)
            ans.push_back(du);
        for(auto viz:adj[u])
            pq.push(make_pair(du + viz.second, viz.first));
    }
    for(auto u:ans)
        cout<<u<<' ';
    cout<<'\n';
    return 0;
}