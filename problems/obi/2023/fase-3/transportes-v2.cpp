#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
typedef long long ll;
const ll INF=1e18;
vector<pair<int,int>> adj[maxn];
bool visited[maxn];
set<int> current[maxn];
ll p[maxn],dist[maxn];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        dist[i]=INF;
    for(int i=1;i<=k;i++)
        cin>>p[i];
    for(int i=0;i<m;i++){
        int a,b,s;
        cin>>a>>b>>s;
        adj[a].push_back(make_pair(b,s));
        adj[b].push_back(make_pair(a,s));
    }
    int a,b,cu=0;
    ll teste=INF;
    cin>>a>>b;
    dist[a]=0;
    for(int i=0;i<(int)adj[a].size();i++){
        if(p[adj[a][i].second]<teste){
            teste=p[adj[a][i].second];
            cu=adj[a][i].second;
        }
    }
    dist[a]=p[cu];
    current[a].insert(cu);
    for(int i=0;i<(int)adj[a].size();i++){
        if(p[cu]==p[adj[a][i].second]){
            current[a].insert(adj[a][i].second);
        }
    }
    priority_queue<pair<ll,int>> q;
    q.push(make_pair(-dist[a],a));
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(visited[x])
            continue;
        visited[x]=true;
        for(auto par:adj[x]){
            int i=par.first,s=par.second;
            if(dist[i]>dist[x]&&current[x].find(s)!=current[x].end()){
                dist[i]=dist[x];
                current[i].clear();
                current[i].insert(s);
                q.push(make_pair(-dist[i],i));
            }else if(dist[i]==dist[x]){
                //current[i].insert(s);
                //q.push(make_pair(-dist[i],i));
            }
            else if(dist[i]>dist[x]+p[s]&&current[x].find(s)==current[x].end()){
                dist[i]=dist[x]+p[s];
                current[i].clear();
                current[i].insert(s);
                q.push(make_pair(-dist[i],i));
            }
        }
    }
    if(dist[b]==INF)
        cout<<-1<<endl;
    else
        cout<<dist[b]<<endl;
}