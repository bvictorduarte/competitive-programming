#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
vector<tuple<int, int , ll>> edges;
vector<pair<int, ll>> adj[maxn];
vector<pair<int, int>> g[maxn];
ll dist_1[maxn];
bool vis_1[maxn];
set<int> out[maxn];
int n, m, vis_2[maxn];
pair<int, int> par[maxn];
void dijkstra_1(int s){
    priority_queue<pair<ll, int>> pq;
    for(int i = 1; i <= n; i++)
        dist_1[i] = LINF;
    dist_1[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if (vis_1[a]) continue;
        vis_1[a] = true;
        for(auto u : adj[a]){
            int b = u.first, w = u.second;
            if(dist_1[a] + w < dist_1[b]){
                dist_1[b] = dist_1[a] + w;
                pq.push(make_pair(-dist_1[b], b));
            }
        }
    }
}
void make_graph(){
    for(int i = 0; i < m; i++){
        int a, b;
        ll w;
        tie(a, b, w) = edges[i];
        if(dist_1[b] == dist_1[a] + w)
            g[a].push_back(make_pair(b, i));
        else if(dist_1[a] == dist_1[b] + w)
            g[b].push_back(make_pair(a, i));
    }
}
void dfs(int v){
    vis_2[v] = true;
    for(auto p : g[v]){
        int u = p.first, idx = p.second;
        if(!vis_2[u]){
            par[u] = make_pair(v, idx);
            out[v].insert(idx);
            dfs(u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
        edges.push_back(make_tuple(a, b, w));
    }
    dijkstra_1(1);
    make_graph();
    dfs(1);
    int cont = 0;
    set<pair<int, int>> pq;
    for(int i = 1; i <= n; i++)
        if(vis_2[i]){
            pq.insert(make_pair((int)out[i].size(), i));
            cont += (int)out[i].size();
        }
    while(cont > k){
        cont--;
        int v = (*pq.begin()).second;
        int dad = par[v].first, idx = par[v].second;
        pq.erase(pq.begin());
        pq.erase(pq.find(make_pair((int)out[dad].size(), dad)));
        out[dad].erase(out[dad].find(idx));
        pq.insert(make_pair((int)out[dad].size(), dad));
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++)
        if(vis_2[i])
            for(auto idx : out[i])
                ans.push_back(idx);
    sort(ans.begin(), ans.end());
    cout << cont << endl;
    for(auto u : ans)
        cout << u + 1 << ' ';
    cout << '\n';
    return 0;
}