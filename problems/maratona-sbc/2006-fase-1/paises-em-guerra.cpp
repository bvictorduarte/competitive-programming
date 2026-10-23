#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[maxn][2],adj_scc[maxn];
vector<int> ord;
vector<tuple<int, int, int>> edges;
int adj_matrix[maxn][maxn];
int comp[maxn],dist[maxn];
int c;
bool visited[maxn][2],vis[maxn];
void dfs(int x, int f){
    visited[x][f] = true;
    if(f)
        comp[x] = c;
    for(auto u : adj[x][f])
        if(!visited[u.first][f])
            dfs(u.first, f);
    if(!f)
        ord.push_back(x);
}
int main(){
    int n, e;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> e && n){
        for(int i = 0; i <= 1; i ++)
            for(int j = 1; j <= n; j++){
                adj[j][i].resize(0);
                visited[j][i]=false;
            }
        edges.resize(0);
        for(int i = 0; i < e; i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a][0].push_back(make_pair(b, w));
            adj[b][1].push_back(make_pair(a, w));
            edges.push_back(make_tuple(a, b, w));
        }
        ord.resize(0);
        for(int i = 1; i <= n; i++)
            if(!visited[i][0])
                dfs(i, 0);
        reverse(ord.begin(),ord.end());
        c = 0;
        for(auto u : ord)
            if(!visited[u][1]){
                c++;
                dfs(u, 1);
            }
        for(int i = 1; i <= c; i++)
            for(int j = 1; j <= c; j++)
                adj_matrix[i][j]=INF;
        for(auto e : edges){
            int a, b, w;
            tie(a, b, w) = e;
            if(comp[a] != comp[b])
                adj_matrix[comp[a]][comp[b]]=min(adj_matrix[comp[a]][comp[b]],w);
        }
        for(int i = 1; i <= c; i++)
            for(int j = 1; j <= c; j++)
                if(adj_matrix[i][j] != INF)
                    adj_scc[i].push_back(make_pair(j, adj_matrix[i][j]));
        int k;
        cin >> k;
        priority_queue<pair<int, int>> pq;
        while(k--){
            int a, b;
            cin >> a >> b;
            for(int i = 1; i <= c; i++){
                dist[i] = INF;
                vis[i]=false;
            }
            dist[comp[a]] = 0;
            pq.push(make_pair(0, comp[a]));
            while(!pq.empty()){
                int u = pq.top().second, du = -pq.top().first;
                pq.pop();
                if(vis[u])continue;
                vis[u]=true;
                for(auto v : adj_scc[u]){
                    dist[v.first]=min(dist[v.first],du+v.second);
                    pq.push(make_pair(-dist[v.first],v.first));
                }
            }
            if(dist[comp[b]]!=INF)
                cout<<dist[comp[b]]<<endl;
            else
                cout<<"Nao e possivel entregar a carta\n";
        }
        cout<<endl;
        for(int i = 1; i <= c; i++)
                adj_scc[i].resize(0);
    }
    return 0;
}