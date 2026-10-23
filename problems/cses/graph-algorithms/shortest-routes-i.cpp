#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+50;
const long long INF=1e18;
vector<pair<int,long long>> adj[MAXN];
priority_queue<pair<long long,int>> q;
bool visited[MAXN];
long long dist[MAXN];
int main(){
    int n,m,a,b;
    long long c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
    }
    for(int i=2;i<=n;i++)
        dist[i]=INF;
    dist[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int s=q.top().second;q.pop();
        if(visited[s])continue;
        visited[s]=true;
        for(auto u:adj[s]){
            int p=u.first;
            long long w=u.second;
            if(dist[p]>dist[s]+w){
                dist[p]=dist[s]+w;
                q.push(make_pair(-dist[p],p));
            }
        }
    }
    for(int i=1;i<=n-1;i++)
        cout<<dist[i]<<" ";
    cout<<dist[n]<<endl;
    return 0;
}