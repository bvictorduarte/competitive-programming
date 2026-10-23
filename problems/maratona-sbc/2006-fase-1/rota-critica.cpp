#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m;
map<string, int> mp;
map<int, string> mp_inv;
vector<int> adj[maxn],aresta[maxn];
bool mark[maxn][maxn], visited[maxn];
vector<pair<int, int>> edges;
void dfs(int x, int id){
    visited[x] = true;
    for(int i = 0; i <(int)adj[x].size(); i++)
        if(aresta[x][i] != id && !visited[adj[x][i]])
            dfs(adj[x][i], id);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m &&!( !n && !m)){
        edges.resize(0);
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            aresta[i].resize(0);
            string s;
            cin >> s;
            mp[s] = i;
            mp_inv[i] = s;
        }
        for(int i = 1; i <= m; i++){
            string a, b;
            cin >> a >> b;
            adj[mp[a]].push_back(mp[b]);
            aresta[mp[a]].push_back(i);
            edges.push_back(make_pair(mp[a],mp[b]));
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < m; i++){
            int a = edges[i].first, b = edges[i].second;
            dfs(a, i+1);
            if(!visited[1])
                mark[a][b] = true;
            for(int i = 1; i <= n; i++)
                visited[i] = false;
        }
        bool tem = false;
        for(auto e:edges){
            int i = e.first, j = e.second;
            if(mark[i][j]){
                mark[i][j] = false;
                cout<<mp_inv[i]<<' '<<mp_inv[j]<<'\n';
                tem = true;
            }
        }
        if(!tem)
            cout << "Nenhuma\n";
        cout << '\n';
    }
    return 0;
}