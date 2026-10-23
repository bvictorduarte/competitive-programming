#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> adj[maxn],articulation_points;
bool visited[maxn];
int low[maxn],pre[maxn],t=0;
void dfs(int v, int p=0){
    ++t;
    int qf=0;
    bool art_point=false;
    visited[v]=true;
    pre[v]=low[v]=t;
    for(auto u:adj[v]){
        if(!visited[u]){
            qf++;
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            if(low[u]>=pre[v])
                art_point=true;
        }else{
            if(u==p)continue;
            low[v]=min(low[v],pre[u]);
        }
    }
    if((p==0&&qf>=2)||(p!=0&&art_point))articulation_points.push_back(v);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);
    cout<<(int)articulation_points.size()<<endl;
    if((int)articulation_points.size()>0)
        cout<<articulation_points[0];
    for(int i=1;i<(int)articulation_points.size();i++)
        cout<<" "<<articulation_points[i];
    cout<<endl;
    return 0;
}