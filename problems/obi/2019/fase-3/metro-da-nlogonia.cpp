#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
vector<int> adj[maxn][2];
int dep[maxn][4],parent[maxn][2];
void dfs1(int t,int x=1, int p=0){
    if(p)
        dep[x][t]=dep[p][t]+1;
    for(auto u:adj[x][t])
        if(u!=p)
            dfs1(t,u,x);
}
void dfs2(int t, int x, int p=0){
    if(p)
        dep[x][t+2]=dep[p][t+2]+1;
    parent[x][t]=p;
    for(auto u:adj[x][t])
        if(u!=p)
            dfs2(t,u,x);
}
int max_depht(int n, int t){
    int max_dep=-1,j_max;
    for(int i=1;i<=n;i++)
        if(max_dep<dep[i][t]){
            max_dep=dep[i][t];
            j_max=i;
        }
    return j_max;
}
int find_parent(int j, int t){
    int m=dep[j][t+2];
    if(m%2==0){
        for(int i=1;i<=(m+1)/2;i++)
            j=parent[j][t];
        return j;
    }
    else{
        int j2;
        for(int i=1;i<=(m+1)/2;i++){
            if(i==m)
                j2=j;
            j=parent[j][t];
        }
        return dep[j][t]>dep[j2][t] ? j : j2;
    }
    return j;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a][0].push_back(b);
        adj[b][0].push_back(a);
    }
    for(int i=1;i<=m-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a][1].push_back(b);
        adj[b][1].push_back(a);
    }
    dfs1(0);
    dfs1(1);
    dfs2(0,max_depht(n,0));
    dfs2(1,max_depht(m,1));
    cout<<find_parent(max_depht(n,2),0)<<" "<<find_parent(max_depht(m,3),1)<<'\n';
    return 0;
}