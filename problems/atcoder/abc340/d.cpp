#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
typedef long long ll;
const ll INF=1e18;
vector<pair<int,ll>> adj[maxn];
ll dist[maxn];
bool visited[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        ll a,b;
        int x;
        cin>>a>>b>>x;
        adj[i].push_back({i+1,a});
        adj[i].push_back({x,b});
    }
    for(int i=2;i<=n;i++)
        dist[i]=INF;
    priority_queue<pair<ll,int>> q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(visited[x])continue;
        visited[x]=true;
        for(auto edge:adj[x]){
            int u=edge.first;
            ll w=edge.second;
            if(dist[u]>dist[x]+w){
                dist[u]=dist[x]+w;
                q.push(make_pair(-dist[u],u));
            }
        }
    }
    cout<<dist[n]<<endl;
    return 0;
}