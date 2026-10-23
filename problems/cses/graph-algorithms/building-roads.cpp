#include <bits/stdc++.h>
using namespace std;
const int MAXN=100050;
vector<int> adj[MAXN];
int parent[MAXN];
bool visited[MAXN],achou=false;
int city;
void dfs(int x,int father){
    visited[x]=true;
    for(auto u:adj[x]){
        if(u!=parent[x]){
            if(visited[u]&&!achou){
                achou=true;
                city=u;
                parent[u]=father;
            }else if(!visited[u]){
                parent[u]=x;
                dfs(u,x);
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1]=0;
    dfs(1,0);
    if(!achou){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int u;
    u=parent[city];
    printf("%d ", city);
    while(u!=city){
        printf("%d ", u);
        u=parent[u];
    }
    printf("%d\n", city);
    return 0;
}