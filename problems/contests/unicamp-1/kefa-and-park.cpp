#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
vector<int> adj[maxn];
int v[maxn],acum[maxn],qc[maxn];
void dfs(int x,int p=0){
    if(!v[x]){
        qc[x]=max(qc[p],acum[p]);        
        acum[x]=0;
    }
    else
        acum[x]=acum[p]+1;
    qc[x]=max(qc[p],acum[x]);
    for(auto u:adj[x]){
        if(u!=p)
            dfs(u,x);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    int ans=0;
    for(int i=2;i<=n;i++)
        if((int)adj[i].size()==1&&qc[i]<=m)
            ans++;
    cout<<ans<<endl;
    return 0;
}