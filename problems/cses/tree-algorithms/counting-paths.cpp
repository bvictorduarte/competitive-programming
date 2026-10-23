#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int dp[maxn],depth[maxn],dplca[maxn][19],n;
vector<int> adj[maxn];
void dfs1(int x, int p){
    dplca[x][0]=p;
    depth[x]=depth[p]+1;
    for(auto u:adj[x])
        if(u!=p)
            dfs1(u,x);
}
void pre_compute(){
    for(int j=1;j<=ceil(log2(maxn));j++)
        for(int i=1;i<=n;i++)
            dplca[i][j]=dplca[dplca[i][j-1]][j-1];
}
int k_ancestor(int x, int k){
    for(int j=ceil(log2(maxn));j>=0;j--)
        if(k&(1<<j))
            x=dplca[x][j];
    return x;
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    a=k_ancestor(a,depth[a]-depth[b]);
    if(a==b)return a;
    for(int k=ceil(log2(maxn));k>=0;k--)
        while(dplca[a][k]!=dplca[b][k]){
            a=dplca[a][k];
            b=dplca[b][k];
        }
    return dplca[a][0];
}
void dfs2(int x, int p){
    for(auto u:adj[x])
        if(u!=p){
            dfs2(u,x);
            dp[x]+=dp[u];
        }
}
int main(){
    int m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int a,b,l;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    pre_compute();
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        dp[a]++;
        dp[b]++;
        l=lca(a,b);
        dp[l]--;
        dp[dplca[l][0]]--;
    }
    dfs2(1,0);
    cout<<dp[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<dp[i];
    cout<<'\n';
    return 0;
}