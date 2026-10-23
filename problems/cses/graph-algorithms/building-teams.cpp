#include <bits/stdc++.h>
using namespace std;
const int MAXN=100050;
int color[MAXN];
vector<int> adj[MAXN];
vector<pair<int,int>> edges;
bool visited[MAXN];
int cont=0;
void dfs(int x){
    if(visited[x])return;
    visited[x]=true;
    for(auto u:adj[x]){
        if(color[x]==1)
            color[u]=2;
        else
            color[u]=1;
        dfs(u);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d", &a,&b);
        edges.push_back(make_pair(a,b));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    color[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        color[i]=1;
        dfs(i);
    }
    for(auto e:edges){
        int a=e.first,b=e.second;
        if(color[a]==color[b]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ", color[i]);
    printf("\n");
    return 0;
}