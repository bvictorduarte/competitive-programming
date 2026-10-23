#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=2*1e5+1;
const ll INF=9*1e18;
ll dist[2][maxN],ans=INF;
bool visited[maxN];
vector<pair<int,ll>> adj[2][maxN];
vector<tuple<int,int,ll>> edges;
void dijkstra(int x, int a){
    priority_queue<pair<ll,int>> q;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=maxN;i++)
        dist[a][i]=INF;
    dist[a][x]=0;
    q.push(make_pair(dist[a][x],x));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(visited[u])continue;
        visited[u]=true;
        for(auto k:adj[a][u]){
            int b=k.first;
            ll w=k.second;
            if(dist[a][u]+w<dist[a][b]){
                dist[a][b]=dist[a][u]+w;
                q.push(make_pair(-dist[a][b],b));
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        edges.push_back(make_tuple(a,b,w));
        adj[0][a].push_back(make_pair(b,w));
        adj[1][b].push_back(make_pair(a,w));
    }
    dijkstra(1,0);
    dijkstra(n,1);
    for(auto e:edges){
        int a,b;
        ll w;
        tie(a,b,w)=e;
        ans=min(ans,dist[0][a]+dist[1][b]+w/2);
    }
    cout<<ans;
    return 0;
}