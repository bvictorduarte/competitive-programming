#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int pre[maxn],low[maxn],t=0,prof[maxn];
bool visited[maxn],is_possible=true;
vector<int> adj[maxn];
vector<pair<int,int>> ans;
void dfs(int x, int p=0){
    t++;
    low[x]=pre[x]=t;
    for(auto u:adj[x]){
        if(!visited[u]){
            visited[u]=true;
            prof[u]=prof[x]+1;
            dfs(u,x);
            low[x]=min(low[x],low[u]);
            ans.push_back(make_pair(x,u));
        }else{
            if(u==p)continue;
            if(prof[x]>prof[u])
                ans.push_back(make_pair(x,u));
            low[x]=min(low[x],pre[u]);
        }
    }
    if(p!=0&&low[x]==pre[x])
        is_possible=false;
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
    int c=0;
    for(int i=1;i<=n;i++)
        if(!visited[i]){
            c++;
            prof[i]++;
            visited[i]=true;
            dfs(i);
        }
    if(is_possible&&c==1)
        for(auto u:ans)
            cout<<u.first<<" "<<u.second<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}