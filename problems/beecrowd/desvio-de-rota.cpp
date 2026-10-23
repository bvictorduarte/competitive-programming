#include<bits/stdc++.h>
using namespace std;
const int maxn=260;
const int INF=0x3f3f3f3f;
int dist[maxn];
bool visited[maxn];
int main(){
    int n,m,c,k;
    while(cin>>n>>m>>c>>k&&n>0){
        vector<pair<int,int>> adj[maxn];
        for(int i=0;i<n;i++){
            dist[i]=INF;
            visited[i]=false;
        }
        for(int i=1;i<=m;i++){
            int a,b,p;
            cin>>a>>b>>p;
            if(a>b)swap(a,b);
            if(b==a+1&&b<=c-1)
                adj[a].push_back(make_pair(b,p));
            else if(a<=c-1&&b>=c)
                adj[b].push_back(make_pair(a,p));
            else if(a>=c){
                adj[b].push_back(make_pair(a,p));
                adj[a].push_back(make_pair(b,p));
            }
        }
        priority_queue<pair<int,int>> q;
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            int a=q.top().second;q.pop();
            if(visited[a])continue;
            visited[a]=true;
            for(auto u:adj[a]){
                if(dist[a]+u.second<dist[u.first]){
                    dist[u.first]=dist[a]+u.second;
                    q.push(make_pair(-dist[u.first],u.first));
                }
            }
        }
        cout<<dist[c-1]<<endl;
    }
}