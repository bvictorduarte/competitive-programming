#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;
vector<int> adj[maxn];
int tam_subtree[maxn],n,ans;
void dfs1(int x, int p){
    int sum=0;
    for(auto u:adj[x]){
        if(u!=p){
            dfs1(u,x);
            sum+=tam_subtree[u];
        }
    }
    tam_subtree[x]=sum+1;
}
int dfs_centroid(int x, int p){
    bool v=true;
    int max_tam=-1,k;
    for(auto u:adj[x])
        if(u!=p){
            if(tam_subtree[u]>n/2)
                v=false;
            if(max_tam<tam_subtree[u]){
                max_tam=tam_subtree[u];
                k=u;
            }
        }
    if(v)
        return x;
    else
        return dfs_centroid(k,x);
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    cout<<dfs_centroid(1,0)<<endl;
    return 0;
}