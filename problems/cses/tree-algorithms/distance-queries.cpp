#include<bits/stdc++.h>
using namespace std;
const int maxN=1<<19;
const int maxLog=19;
typedef long long ll;
ll ancestor[maxN][maxLog],depth[maxN],n;
vector<ll> adj[maxN];
void dfs(ll x, ll p){
    for(auto u:adj[x]){
        if(u!=p){
            depth[u]=depth[x]+1;
            dfs(u,x);
            ancestor[u][0]=x;
        }
    }
}
void precompute(){
    for(ll k=1;k<maxLog;k++)
        for(ll i=1;i<=n;i++)
            ancestor[i][k]=ancestor[ancestor[i][k-1]][k-1];
}
ll ancest(ll x, ll k){
    for(int i=0;i<log2(k)+1;i++)
        if(k&(1<<i))
            x=ancestor[x][i];
    return x;
}
ll lca(ll a, ll b){
    if(depth[a]!=depth[b]){
        if(depth[a]>depth[b])
            swap(a,b);
        b=ancest(b,depth[b]-depth[a]);
    }
    if(a==b)
        return a;
    for(int i=maxLog-1;i>=0;i--)
        if(ancestor[a][i]!=ancestor[b][i]){
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    return ancestor[a][0];
}
int main(){
    ll q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        ll a,b;
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    precompute();
    for(int i=0;i<q;i++){
        ll a,b;
        scanf("%lld %lld", &a, &b);
        cout<<depth[a]+depth[b]-2*depth[lca(a,b)]<<endl;
    }
    return 0;
}