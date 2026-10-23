#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
vector<int> d(maxn,INF),adj[maxn];
int ans[maxn],n,v[maxn];
void dfs(int x=1, int p=0){
    int l=lower_bound(d.begin(),d.begin()+(n+1),v[x])-d.begin();
    if(l==ans[p]+1)
        ans[x]=ans[p]+1;
    else
        ans[x]=ans[p];
    int aux;
    aux=d[l];
    d[l]=v[x];
    for(auto u:adj[x])
        if(u!=p)
            dfs(u,x);
    d[l]=aux;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    d[0]=0;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin>>v[i];
    dfs();
    for(int i=2;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}