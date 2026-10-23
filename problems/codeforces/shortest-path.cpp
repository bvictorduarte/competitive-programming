#include<bits/stdc++.h>
using namespace std;
const int maxn = 3050;
vector<int> adj[maxn];
int dist[maxn][maxn];
bool vis[maxn][maxn];
map<tuple<int, int , int> , bool>  mp;
map<pair<int, int>, pair<int, int>> prv;
int n, m, k;
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        mp[make_tuple(a, b, c)] = true;
    }
    queue<pair<int, int>> q;
    q.push({0, 1});
    vis[0][1] = true;
    int aux = -1;
    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();
        if(b == n){
            aux = a;
            break;
        }
        for(auto c : adj[b]){
            if(vis[b][c] || mp[make_tuple(a, b, c)]) continue;
            vis[b][c] = true;
            dist[b][c] = dist[a][b] + 1;
            prv[make_pair(b, c)] = make_pair(a, b);
            q.push({b, c});
        }
    }
    if(aux == -1){
        cout << -1 << endl;
        return 0;
    }
    cout << dist[aux][n] << endl;
    pair<int, int> cur = make_pair(aux, n);
    vector<int> ans;
    while(cur != make_pair(0, 1)){
        ans.push_back(cur.second);
        cur = prv[cur];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans[0];
    for(int i = 1; i < (int)ans.size(); i++)
        cout << ' ' << ans[i];
    cout << '\n';
    return 0;
}