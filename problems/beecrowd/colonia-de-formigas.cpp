#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+50;
const ll maxl=20;
vector<pair<ll,ll>> adj[maxn];
ll n,q,dp[maxn][maxl],dist[maxn],prof[maxn];
void dfs(ll x, ll p){
    dp[x][0]=p;
    for(auto u:adj[x]){
        ll f=u.first,w=u.second;
        if(f!=p){
            dist[f]=dist[x]+w;
            prof[f]=prof[x]+1;
            dfs(f,x);
        }
    }
}
void pre_compute(){
    for(int k=1;k<=18;k++){
        for(int i=0;i<=n-1;i++)
            if(dp[i][k-1]!=-1)
                dp[i][k]=dp[dp[i][k-1]][k-1];
            else
                dp[i][k]=-1;
    }
}
ll ancestor(ll a, ll k){
    for(ll i=18;i>=0;i--)
        if(k&(1<<i))
            a=dp[a][i];
    return a;
}
ll lca(ll a, ll b){
    if(prof[a]>prof[b])swap(a,b);
    b=ancestor(b,(prof[b]-prof[a]));
    if(a==b)return a;
    for(int k=18;k>=0;k--)
        while(dp[a][k]!=dp[b][k]){
            a=dp[a][k];
            b=dp[b][k];
        }
    return dp[a][0];
}
int main(){
    ll a,b;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n&&n){
        for(int i=0;i<=n-1;i++)
            adj[i].resize(0);
        for(int i=1;i<=n-1;i++){
            cin>>a>>b;
            adj[i].push_back(make_pair(a,b));
            adj[a].push_back(make_pair(i,b));
        }
        dfs(0,0);
        dp[0][0]=-1;
        pre_compute();
        cin>>q;
        for(ll i=0;i<q-1;i++){
            cin>>a>>b;
            cout<<dist[a]+dist[b]-2*dist[lca(a,b)]<<' ';
        }
        cin>>a>>b;
        cout<<dist[a]+dist[b]-2*dist[lca(a,b)]<<'\n';
    }
    return 0;
}