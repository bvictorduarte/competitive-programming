#include<bits/stdc++.h>
using namespace std;
const int maxN=1<<19;
const int maxLog=19;
int ancestor[maxN][maxLog],n,depth[maxN];
vector<int> adj[maxN];
void dfs(int x, int p){
    for(auto u:adj[x])
        if(u!=p){
            depth[u]=depth[x]+1;
            dfs(u,x);
        }
}
void pre_compute(){
    for(int k=1;k<maxLog;k++)
        for(int i=1;i<=n;i++)
            ancestor[i][k]=ancestor[ancestor[i][k-1]][k-1];
}
int ancest(int a, int k){
    for(int i=0;i<log2(k)+1;i++)
        if(k&(1<<i))
            a=ancestor[a][i];
    return a;
}
int lca(int a, int b){
    if(depth[a]!=depth[b]){
        if(depth[a]>depth[b])
            swap(a,b);
        b=ancest(b,depth[b]-depth[a]);
    }
    if(a==b)
        return a;
    for(int i=maxLog-1;i>=0;i--)
        if(ancestor[a][i]!=ancestor[b][i]){
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    return ancestor[a][0];
}
int main(){
    int q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        scanf("%d", &ancestor[i][0]);
        adj[ancestor[i][0]].push_back(i);
    }
    depth[1]=0;
    dfs(1,0);
    pre_compute();
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}