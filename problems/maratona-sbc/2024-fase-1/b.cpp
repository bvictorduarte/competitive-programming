#include<bits/stdc++.h>
using namespace std;
const int maxn = 150;
const int maxm = 1e6 + 50;
const int INF = 0x3f3f3f3f;
vector<int> filme[maxn], adj[maxn], ator[maxm];
set<int> have[maxn];
bool am[maxn][maxn];
int dist[maxn], dad[maxn];
bool vis[maxn];
void bfs(int s, int n){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        vis[i] = false;
    }
    for(auto u : ator[s]){
        vis[u] = true;
        dist[u] = 0;
        q.push(u);
        dad[u] = u;
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[v] + 1;
            dad[u] = v;
            q.push(u);
        }
    }
}
void print(int a, int b, int fb){
    vector<int> ans;
    ans.push_back(b);
    ans.push_back(fb);
    while(fb != dad[fb]){
        for(auto k : filme[fb])
            if(have[fb].find(k) != have[fb].end() && have[dad[fb]].find(k) != have[dad[fb]].end()){
                ans.push_back(k);
                break;
            }
        fb = dad[fb];
        ans.push_back(fb);
    }
    ans.push_back(a);
    reverse(ans.begin(), ans.end());
    cout << ((int)ans.size() + 1) / 2 << '\n';
    for(auto u : ans)
        cout << u << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int ni;
        cin >> ni;
        for(int j = 1; j <= ni; j++){
            int a;
            cin >> a;
            filme[i].push_back(a);
            ator[a].push_back(i);
            have[i].insert(a);
        }
    }
    for(int i = 1; i <= n; i++){
        am[i][i] = true;
        for(auto id : filme[i])
            for(auto f : ator[id])
                if(!am[i][f]){
                    am[i][f] = am[f][i] = true;
                    adj[i].push_back(f);
                    adj[f].push_back(i);
                }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        bfs(a, n);
        if(ator[b].empty()){
            cout << -1 << endl;
            continue;
        }
        int best = ator[b][0];
        for(auto f : ator[b])
            if(dist[f] < dist[best])
                best = f;
        if(dist[best] == INF)
            cout << -1 << endl;
        else
            print(a, b, best);
    }
    return 0;
}