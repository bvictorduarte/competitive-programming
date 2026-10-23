#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
const int INF=1e9;
int filhos[maxn],dp[maxn][20],ans[maxn],dad[maxn],depth[maxn];
bool erase[maxn];
vector<int> adj[maxn];
void find_size(int v, int p=-1){
    filhos[v]=1;
    for(auto u:adj[v]){
        if(u!=p&&!erase[u]){
            find_size(u,v);
            filhos[v]+=filhos[u];
        }
    }
}
int find_centroid(int v,int n,int p=-1){
    bool centroid=true;
    int viz;
    for(auto u:adj[v])
        if(u!=p&&!erase[u])
            if(filhos[u]>(n/2)){
                centroid=false;
                viz=u;
            }
    if(centroid)
        return v;
    else
        return find_centroid(viz,n,v);
}
void build(int r=1, int p=-1){
    find_size(r);
    int centroid=find_centroid(r,filhos[r]);
    if(p==-1)
        p=centroid;
    dad[centroid]=p;
    erase[centroid]=true;
    for(auto u:adj[centroid])
        if(!erase[u])
            build(u,centroid);
}
void find_depth(int x=1, int p=0){
    depth[x]=depth[p]+1;
    dp[x][0]=p;
    for(auto u:adj[x])
        if(u!=p)
            find_depth(u,x);
}
void pre_compute(int n){
    for(int k=1;k<=18;k++)
        for(int i=1;i<=n;i++)
            dp[i][k]=dp[dp[i][k-1]][k-1];
}
int ancestor(int a, int k){
    for(int i=18;i>=0;i--)
        if(k&(1<<i))
            a=dp[a][i];
    return a;
}
int lca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    a=ancestor(a,depth[a]-depth[b]);
    if(a==b)return a;
    for(int k=18;k>=0;k--)
        while(dp[a][k]!=dp[b][k]){
            a=dp[a][k];
            b=dp[b][k];
        }
    return dp[a][0];
}
int dist(int a, int b){
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}
void set_ans(int n){
    for(int i=1;i<=n;i++)
        ans[i]=INF;
}
void update(int x){
    ans[x]=0;
    int it=x;
    while(it!=dad[it]){
        it=dad[it];
        ans[it]=min(ans[it],dist(it,x));
    }
}
int query(int x){
    int resp=ans[x],it=x;
    while(it!=dad[it]){
        it=dad[it];
        resp=min(resp,ans[it]+dist(it,x));
    }
    return resp;
}
int main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build();
    find_depth();
    pre_compute(n);
    set_ans(n);
    update(1);
    for(int i=0;i<m;i++){
        int op,x;
        cin>>op>>x;
        if(op==1)
            update(x);
        else
            cout<<query(x)<<'\n';
    }
    return 0;
}