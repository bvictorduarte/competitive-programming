#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
int quant_universities[maxn];
vector<int> adj[maxn];
void dfs1(int v, int pai=0){
    for(auto u:adj[v])
        if(u!=pai){
            dfs1(u,v);
            quant_universities[v]+=quant_universities[u];
        }
}
int main(){
    int n,k;
    long long ans=0;
    cin>>n>>k;
    for(int i=0;i<2*k;i++){
        int a;
        cin>>a;
        quant_universities[a]++;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1);
    for(int i=1;i<=n;i++)
        ans+=min((long long)(2*k-quant_universities[i]),(long long)quant_universities[i]);
    cout<<ans<<endl;
    return 0;
}