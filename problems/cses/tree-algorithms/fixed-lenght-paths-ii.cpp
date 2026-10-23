#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
#define LSOne(k) (k&(-k))
typedef long long ll;
vector<int> adj[maxn];
int sz[maxn],dist[maxn],max_dist,n,k1,k2;
ll bit[maxn],ans=0;
bool removed[maxn];
void update(int k, ll a){
    for(;k<=n;k+=LSOne(k))
        bit[k]+=a;
}
ll query(int k){
    ll sum=0;
    for(;k;k-=LSOne(k))
        sum+=bit[k];
    return sum;
}
int find_sizes(int x, int p=0){
    sz[x]=1;
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            sz[x]+=find_sizes(u,x);
    return sz[x];
}
int find_centroid(int x,int tam, int p=0){
    for(auto u:adj[x])
        if(u!=p&&!removed[u]&&2*sz[u]>tam)
            return find_centroid(u,tam,x);
    return x;
}
void compute_paths(int x,int k1, int k2 ,int p=0){
    dist[x]=dist[p]+1;
    if(dist[x]>k2)return;
    if(k1-dist[x]>=1)
        ans+=query(k2-dist[x])-query(k1-dist[x]-1);
    else
        ans+=query(k2-dist[x])+1LL;
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            compute_paths(u,k1,k2,x);
}
void compute_dist(int x, int p=0){
    dist[x]=dist[p]+1;
    max_dist=max(max_dist,dist[x]);
    update(dist[x],1LL);
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            compute_dist(u,x);
}
void decompose(int x=1, int p=0){
    int centroid=find_centroid(x,find_sizes(x));
    removed[centroid]=true;
    max_dist=0;
    for(auto u:adj[centroid])
        if(u!=p&&!removed[u]){
            compute_paths(u,k1,k2);
            compute_dist(u);
        }
    for(int i=1;i<=max_dist;i++)
        update(i,-query(i)+query(i-1));
    for(auto u:adj[centroid])
        if(u!=p&&!removed[u])
            decompose(u,centroid);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k1>>k2;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decompose();
    cout<<ans<<endl;
    return 0;
}