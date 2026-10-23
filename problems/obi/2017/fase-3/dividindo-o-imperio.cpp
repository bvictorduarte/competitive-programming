#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<19;
vector<int> adj[maxn];
int tam_subtree[maxn];
int mod(int x){
    if(x>=0)
        return x;
    return -x;
}
void dfs(int x, int p){
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            tam_subtree[x]+=tam_subtree[u];
        }
    tam_subtree[x]++;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    int ans=n+1;
    for(int i=1;i<=n;i++)
        ans=min(ans,mod(n-2*tam_subtree[i]));
    cout<<ans;
}