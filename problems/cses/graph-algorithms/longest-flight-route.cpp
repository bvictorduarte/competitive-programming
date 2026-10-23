#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
vector<int> ts,adj[maxn],r_adj[maxn],ans;
bool visited[maxn];
int dp[maxn],p[maxn];
void topsort(int u){
    visited[u]=true;
    for(auto v:adj[u])
        if(!visited[v])
            topsort(v);
    ts.push_back(u);
}
int main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        r_adj[b].push_back(a);
    }
    topsort(1);
    if(!visited[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    reverse(ts.begin(),ts.end());
    for(auto u:ts)
        for(auto v:r_adj[u]){
            if(dp[u]<dp[v]+1&&visited[v]){
                dp[u]=dp[v]+1;
                p[u]=v;
            }
        }
    for(int cur=n;;cur=p[cur]){
        ans.push_back(cur);
        if(cur==1)break;
    }
    cout<<dp[n]+1<<endl;
    reverse(ans.begin(),ans.end());
    for(auto u:ans)
        cout<<u<<' ';
    cout<<'\n';
    return 0;
}