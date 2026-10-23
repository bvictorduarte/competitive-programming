#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
typedef long long ll;
const ll LINF=0x3f3f3f3f3f3f3f3f;
ll dist[maxn];
bool have=false,visited[maxn];
int n,m;
vector<int> adj[maxn];
vector<tuple<int,int,ll>> edges;
void dfs(int x,int a){
    if(x==a)have=true;
    if(visited[x])return;
    visited[x]=true;
    for(auto u:adj[x])
        dfs(u,a);
}
bool belman_ford(){
    for(int i=2;i<=n;i++)
        dist[i]=LINF;
    for(int i=1;i<=n-1;i++)
        for(auto edge:edges){
            int a,b;
            ll w;
            tie(a,b,w)=edge;
            dist[b]=min(dist[b],dist[a]+w);
        }
    for(auto edge:edges){
        int a,b;
        ll w;
        tie(a,b,w)=edge;
        if(dist[a]+w<dist[b]){
            for(int i=1;i<=n;i++)
                visited[i]=false;
            dfs(1,a);
            if(!have)continue;
            have=false;
            for(int i=1;i<=n;i++)
                visited[i]=false;
            dfs(a,n);
            if(have)
                return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        edges.push_back(make_tuple(a,b,-w));
        adj[a].push_back(b);
    }
    if(belman_ford())
        cout<<-1<<endl;
    else
        cout<<-dist[n]<<endl;
    return 0;
}