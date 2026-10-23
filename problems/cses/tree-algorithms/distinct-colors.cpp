#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int c[maxn],ans[maxn];
vector<int> adj[maxn];
set<int> colors[maxn];
void dfs(int x=1, int p=0){
    colors[x].insert(c[x]);
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            if((int)colors[x].size()<(int)colors[u].size())//small-to-large technique
                swap(colors[x],colors[u]);
            for(auto u:colors[u])
                colors[x].insert(u);
        }
    ans[x]=(int)colors[x].size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout<<ans[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<ans[i];
    cout<<'\n';
}