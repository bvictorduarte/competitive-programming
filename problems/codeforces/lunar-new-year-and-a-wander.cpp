#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int n, m;
vector<int> adj[maxn];
bool vis[maxn];
vector<int> ans;
void solve(){
    priority_queue<int> pq;
    pq.push(-1);
    vis[1] = true;
    while(!pq.empty()){
        int v = -pq.top(); pq.pop();
        ans.push_back(v);
        for(auto u : adj[v])
            if(!vis[u]){
                pq.push(-u);
                vis[u] = true;
            }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    for(auto u : ans)
        cout << u << ' ';
    cout << endl;
    return 0;
}