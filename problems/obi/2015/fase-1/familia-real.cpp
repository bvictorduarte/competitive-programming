#include <bits/stdc++.h>
using namespace std;
int p,f[10050],dist[10050],visitado[10050],df[10050],df2[10050];
vector<int> adj[10050];
void bfs(int x){
    int s,u;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(int i=0;i<(int)adj[s].size();i++){
            u=adj[s][i];
            if(visitado[u])
                continue;
            visitado[u]=1;
            dist[u]=dist[s]+1;
            q.push(u);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d", &p);
        adj[p].push_back(i);
    }
    for(int i=1;i<=m;i++)
        scanf("%d", &f[i]);
    dist[0]=0;
    bfs(0);
    for(int i=1;i<=n;i++){
        df[dist[i]]++;
    }
    for(int i=1;i<=m;i++){
        df2[dist[f[i]]]++;
    }
    for(int i=1;i<=n;i++){
        if(df[i]>0)
            printf("%.2f ", 100.0-100.0*(((float)df[i]-(float)df2[i])/(float)df[i]));
    }
    printf("\n");

}
