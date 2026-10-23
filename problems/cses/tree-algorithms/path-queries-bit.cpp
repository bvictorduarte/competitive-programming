#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
#define LSOne(n) (n&-(n))
typedef long long int ll;
ll ft[2*maxn],v[maxn],dist[maxn];
vector<int> adj[maxn];
int n,posi[maxn],tin,tam_sub[maxn];
void dfs(int x, int p){
    posi[x]=++tin;
    dist[posi[x]]=dist[posi[p]]+v[x];
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            tam_sub[x]+=tam_sub[u];
        }
    tam_sub[x]++;
}
void update(int i, ll x){
    for(; i<=n;i+=LSOne(i))
        ft[i]+=x;
}
ll pq(int i){
    ll sum=0;
    for(;i;i-=LSOne(i))
        sum+=ft[i];
    return sum;
}
int main(){
    int q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        update(posi[i],dist[posi[i]]);
        update(posi[i]+1,-dist[posi[i]]);
    }
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int s,x;
            cin>>s>>x;
            update(posi[s],x-v[s]);
            update(posi[s]+tam_sub[s],-x+v[s]);
            v[s]=x;
        }else{
            int s;
            cin>>s;
            cout<<pq(posi[s])<<endl;
        }
    }
    return 0;
}