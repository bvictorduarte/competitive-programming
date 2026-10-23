#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
typedef long long ll;
ll val[maxn],val_comp[maxn];
stack<int> t_out;
bool visited[maxn][5];
vector<int> adj[maxn][5],adj_scc[maxn];
int comp[maxn];
void dfs(int x, int p){
    if(visited[x][p])return;
    visited[x][p]=true;
    if(p==2)
        val_comp[comp[x]]+=val[x];
    for(auto u:adj[x][p]){
        if(p==2&&!comp[u])
            comp[u]=comp[x];
        dfs(u,p);
    }
    if(p==1)
        t_out.push(x);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a][1].push_back(b);
        adj[b][2].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i][1])
            dfs(i,1);
    int c=0;
    while(!t_out.empty()){
        int i=t_out.top();t_out.pop();
        if(!visited[i][2]){
            c++;
            comp[i]=c;
            dfs(i,2);
        }
    }
    for(int i=1;i<=n;i++)
        for(auto u:adj[i][1])
            if(comp[u]!=comp[i])
                adj_scc[comp[u]].push_back(comp[i]);
    ll ans=0;
    for(int i=1;i<=c;i++){
        ll k=0;
        for(auto u:adj_scc[i])
            k=max(val_comp[u],k);
        val_comp[i]+=k;
        ans=max(ans,val_comp[i]);
    }
    cout<<ans<<endl;
}