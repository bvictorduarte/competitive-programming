#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
typedef long long ll;
vector<int> adj[maxn];
bool removed[maxn];
int tam_sub[maxn],deepest,dist[maxn],k;
ll ans=0,cont[maxn];
int find_tams(int x, int p=0){
    tam_sub[x]=1;
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            tam_sub[x]+=find_tams(u,x);
    return tam_sub[x];
}
int find_centroid(int x, int tam, int p=0){
    for(auto u:adj[x])
        if(u!=p&&!removed[u]&&2*tam_sub[u]>tam)
            return find_centroid(u,tam,x);
    return x;
}
void compute_paths(int x, int p=0){
    dist[x]=dist[p]+1;
    if(dist[x]>k)return;
    ans+=cont[k-dist[x]];
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            compute_paths(u,x);
}
void compute_distances(int x, int p=0){
    dist[x]=dist[p]+1;
    deepest=max(deepest,dist[x]);
    cont[dist[x]]++;
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            compute_distances(u,x);
}
void decompose(int x=1, int p=0){
    int centroid=find_centroid(x,find_tams(x));
    removed[centroid]=true;
    cont[0]=1;
    deepest=0;
    for(auto u:adj[centroid])
        if(u!=p&&!removed[u]){
            compute_paths(u);
            compute_distances(u);
        }
    fill(cont,cont+deepest+1,0);
    for(auto u:adj[centroid])
        if(u!=p&&!removed[u])
            decompose(u,centroid);
}
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decompose();
    cout<<ans<<endl;
}