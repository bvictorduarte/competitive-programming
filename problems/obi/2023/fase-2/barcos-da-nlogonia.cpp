#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
const int maxl=50;
const int INF=0x3f3f3f3f;
int n,b,link[maxn],sz[maxn],depth[maxn],dp[maxn][maxl],ancestor[maxn][maxl];
vector<pair<int,pair<int,int>>> edges;
vector<pair<int,int>> adj[maxn];
int find(int x){
    while(x!=link[x])x=link[x];
    return x;
}
bool same(int a, int b){
    return find(a)==find(b);
}
void unite(int a, int b){
    a=find(a);
    b=find(b);
    if(sz[b]<sz[a])swap(a,b);
    sz[b]+=sz[a];
    link[a]=b;
}
void set_mst(){
    for(int i=1;i<=n;i++){
        link[i]=i;
        sz[i]=1;
    }
    sort(edges.rbegin(),edges.rend());
    for(auto edge:edges){
        int a=edge.second.first,b=edge.second.second,w=edge.first;
        if(same(a,b))continue;
        unite(a,b);
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
}
void dfs(int x, int p){
    depth[x]=depth[p]+1;
    ancestor[x][0]=p;
    for(auto u:adj[x])
        if(u.first!=p){
            int f=u.first,w=u.second;
            dfs(f,x);
            dp[f][0]=w;
        }
}
void set_dp(){
    dfs(1,0);
}
void pre_compute_lca(){
    for(int j=1;j<=ceil(log2(maxn));j++)
        for(int i=2;i<=n;i++){
            ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
            dp[i][j]=min(dp[i][j-1],dp[ancestor[i][j-1]][j-1]);
        }
}
pair<int,int> k_ancestor(int a, int k){
    int p_min=INF;
    for(int i=31;i>=0;i--)
        if(k&(1<<i)){
            p_min=min(p_min,dp[a][i]);
            a=ancestor[a][i];
        }
    return make_pair(a,p_min);
}
int lca_p(int a,int b){
    int p_min;
    if(depth[a]<depth[b])swap(a,b);
    pair<int,int> aux=k_ancestor(a,depth[a]-depth[b]);
    a=aux.first;
    p_min=aux.second;
    for(int i=31;i>=0;i--){
        while(ancestor[a][i]!=ancestor[b][i]){
            p_min=min(p_min,dp[a][i]);
            p_min=min(p_min,dp[b][i]);
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    }
    if(a!=b){
        p_min=min(p_min,dp[a][0]);
        p_min=min(p_min,dp[b][0]);
    }
    return p_min;
}
int main(){
    cin>>n>>b;
    for(int i=1;i<=b;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back(make_pair(w,make_pair(a,b)));
    }
    set_mst();
    set_dp();
    pre_compute_lca();
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca_p(a,b)<<endl;
    }
    return 0;
}