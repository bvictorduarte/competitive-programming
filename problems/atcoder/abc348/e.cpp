#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+50;
const ll LINF=0x3f3f3f3f3f3f3f3fLL;
vector<ll> adj[maxn];
ll dp[maxn],c[maxn],dist[maxn],n,ans[maxn],sum_c=0;
ll bfs(ll x){
    for(ll i=1;i<=n;i++)
        dist[i]=LINF;
    dist[x]=0;
    queue<ll> q;
    q.push(x);
    while(!q.empty()){
        ll a=q.front();q.pop();
        for(auto u:adj[a])
            if(dist[u]==LINF){
                dist[u]=dist[a]+1;
                q.push(u);
            }
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
        sum+=dist[i]*c[i];
    return sum;
}
void dfs(ll x,ll p){
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            dp[x]+=dp[u];
        }
}
void find_ans(ll x, ll p){
    if(p!=0)
        ans[x]=ans[p]+sum_c-2*dp[x];
    for(auto u:adj[x])
        if(u!=p)
            find_ans(u,x);
}
int main(){
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(ll i=1;i<=n;i++){
        cin>>c[i];
        dp[i]=c[i];
        sum_c+=c[i];
    }
    ans[1]=bfs(1);
    dfs(1,0);
    find_ans(1,0);
    ll min_ans=LINF;
    for(ll i=1;i<=n;i++)
        min_ans=min(min_ans,ans[i]);
    cout<<min_ans<<endl;
    return 0;
}