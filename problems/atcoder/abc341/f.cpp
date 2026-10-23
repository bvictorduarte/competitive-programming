#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+50;
typedef long long ll;
vector<int> adj[maxn];
bool possible[maxn];
ll w[maxn],a[maxn],dp[maxn],sp[maxn];
vector<pair<ll,int>> ord;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
        ord.push_back({w[i],i});
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(ord.begin(),ord.end());
    for(auto p:ord){
        int v=p.second;
        for(int i=0;i<=5001;i++){
            sp[i]=0;
            possible[i]=false;
        }
        ll max_sp=0;
        possible[0]=true;
        for(auto u:adj[v]){
            for(int x=w[v]-w[u];x>=0;x--){
                possible[x+w[u]]|=possible[x];
                if(x+w[u]<w[v]&&possible[x+w[u]]){
                    sp[x+w[u]]=max(sp[x+w[u]],sp[x]+dp[u]);
                    max_sp=max(max_sp,sp[x+w[u]]);
                }
            }
        }
        dp[v]=1+max_sp;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i]*a[i];
    cout<<ans<<endl;
    return 0;
}