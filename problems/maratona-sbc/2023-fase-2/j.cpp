#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
const int INF=0x3f3f3f3f;
vector<int> adj[maxn];
int sz[maxn],parent[maxn],dist_min[maxn],dp[maxn][20],dep[maxn],n,ans[maxn];
set<pair<pair<int,int>,pair<int,int>>> s[maxn];
bool removed[maxn];
void dfs(int x=1,int p=0){
    dp[x][0]=p;
    dep[x]=dep[p]+1;
    for(auto u:adj[x])
        if(u!=p)
            dfs(u,x);
}
void pre_compute(){
    for(int j = 1; j <= ceil(log2(maxn)); j++)
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int ancestor(int x, int k){
    for(int j = ceil(log2(maxn)); j >= 0; j--)
        if(k & (1 << j))
            x = dp[x][j];
    return x;
}
int lca(int a,int b){
    if(dep[a] < dep[b])
        swap(a, b);
    a = ancestor(a, dep[a]-dep[b]);
    if(a == b)
        return a;
    for(int i = ceil(log2(maxn)); i >= 0; i--)
        while(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    return dp[a][0];
}
int dist(int a,int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
int find_sz(int x, int p=0){
    sz[x]=1;
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            sz[x]+=find_sz(u,x);
    return sz[x];
}
int find_centroid(int x, int tam, int p=0){
    for(auto u:adj[x])
        if(u!=p&&!removed[u]&&2*sz[u]>tam)
            return find_centroid(u,tam,x);
    return x;
}
void compute_dist_centroid(int x,int centroid, int p=0,int d=0){
    s[centroid].insert(make_pair(make_pair(x,d),make_pair(d,x)));
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            compute_dist_centroid(u,centroid,x,d+1);
}
void decompose(int x=1, int p=0){
    int centroid=find_centroid(x,find_sz(x));
    removed[centroid]=true;
    parent[centroid]=p;
    compute_dist_centroid(centroid,centroid);
    for(auto u:adj[centroid])
        if(u!=p&&!removed[u])
            decompose(u,centroid);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decompose();
    dfs();
    pre_compute();
    for(int i=1;i<=n;i++){
        int t=(int)s[i].size();
        if(t>=2){
            auto it=s[i].rbegin();
            auto it1=s[i].rbegin();
            it++;
            for(;it!=s[i].rend();it++){
                if((*it1).second.first>=(*it).first.second){
                    int idx=(*it).first.first,d=(*it).first.second,d_min=(*it).first.second,idx_min=(*it).first.first;
                    s[i].erase(s[i].find(*it));
                    s[i].insert(make_pair(make_pair(idx,d),make_pair(d_min,idx_min)));
                }else{
                    int idx=(*it).first.first,d=(*it).first.second,d_min=(*it1).second.first,idx_min=(*it1).second.second;
                    s[i].erase(s[i].find(*it));
                    s[i].insert(make_pair(make_pair(idx,d),make_pair(d_min,idx_min)));
                }
                it1++;
            }
        }
    }
    ans[n]=n;
    for(int i=1;i<n;i++){
        dist_min[i]=INF;
        int p=i;
        while(p){
            auto it=s[p].lower_bound(make_pair(make_pair(i+1,0),make_pair(0,0)));
            if(it!=s[p].end()){
                if(dist_min[i]>(*it).second.first+dist(i,p)){
                    dist_min[i]=(*it).second.first+dist(i,p);
                    ans[i]=(*it).second.second;
                }else if(dist_min[i]==(*it).second.first+dist(i,p)&&ans[i]>(*it).second.second&&i<(*it).second.second)
                    ans[i]=(*it).second.second;
            }
            p=parent[p];
        }
    }
    cout<<ans[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}