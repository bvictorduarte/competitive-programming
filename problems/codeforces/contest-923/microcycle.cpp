#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<pair<int,int>> adj[maxn];
int tin[maxn],low[maxn],comp[maxn],dad[maxn],last;
bool visited[maxn],found,vis[maxn];
stack<int> tarj;
int t=0,c=0;
void dfs(int v, int p=0){
    visited[v]=true;
    tarj.push(v);
    tin[v]=low[v]=++t;
    for(auto edge:adj[v]){
        int u=edge.first;
        if(!visited[u]){
            dfs(u,v);
            low[v]=min(low[v],low[u]);
        }else{
            if(u==p)continue;
            low[v]=min(low[v],tin[u]);
        }
    }
    if(low[v]==tin[v]){
        c++;
        comp[v]=c;
        while(tarj.top()!=v){
            comp[tarj.top()]=c;
            tarj.pop();
        }
        tarj.pop();
    }
}
void find_cycle(int v,int p, int f){
    if(found)return;
    if(!dad[v])
        dad[v]=p;
    for(auto edge:adj[v]){
        int a=edge.first;
        if(comp[v]!=comp[a])continue;
        if(a==p)continue;
        if(a==f){
            last=v;
            found=true;
            break;
        }
        if(!vis[a]){
            vis[a]=true;
            find_cycle(a,v,f);
        }
    }
}
int main(){
    int q;
    cin>>q;
    while(q--){
        c=t=last=0;
        found=false;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n+1;i++){
            adj[i].clear();
            tin[i]=low[i]=comp[i]=dad[i]=0;
            visited[i]=vis[i]=false;
        }
        for(int i=0;i<m;i++){
            int a,b,w;
            scanf("%d%d%d", &a, &b, &w);
            adj[a].push_back(make_pair(b,w));
            adj[b].push_back(make_pair(a,w));
        }
        for(int i=1;i<=n;i++)
            if(!visited[i])
                dfs(i);
        int wm=1e6+50;
        pair<int,int> dup;
        for(int i=1;i<=n;i++){
            for(auto edge:adj[i]){
                int a=edge.first,w=edge.second;
                if(comp[i]==comp[a]&&w<wm){
                    dup=make_pair(i,a);
                    wm=w;
                }
            }
        }
        adj[dup.first].clear();
        adj[dup.first].push_back(make_pair(dup.second,wm));
        find_cycle(dup.first,0,dup.first);
        stack<int> ans;
        int v=last;
        int cont=1;
        while(v!=dup.first){
            cont++;
            ans.push(v);
            v=dad[v];
        }
        cout<<wm<<" "<<cont<<endl;
        cout<<dup.first;
        while(!ans.empty()){
            printf(" %d", ans.top());
            ans.pop();
        }
        cout<<endl;
    }
}