#include <bits/stdc++.h>
using namespace std;
int toca[1050][1050];
vector<int> adj[1000050];
int val[1000050];
int dist[1000050];
int visitado[1000050];
int bfs(int x){
    queue<int> q;
    int s;
    q.push(x);
    dist[x]=0;
    visitado[x]=1;
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(int i=0;i<adj[s].size();i++){
            int u=adj[s][i];
            if(visitado[u])continue;
            visitado[u]=1;
            dist[u]=dist[s]+1;
            q.push(u);
            if(val[u]==2)
                return(dist[u]);
        }
    }

}
int main(){
    int x,y,n,m;
    freopen("input.txt","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &toca[i][j]);
            if(toca[i][j]==3){
                x=i;
                y=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(toca[i][j]!=0){
                val[(i-1)*m+j]=toca[i][j];
                if(i>1&&toca[i-1][j]!=0)
                    adj[(i-1)*m+j].push_back((i-2)*m+j);
                if(i<n&&toca[i+1][j]!=0)
                    adj[(i-1)*m+j].push_back((i)*m+j);
                if(j>1&&toca[i][j-1]!=0)
                    adj[(i-1)*m+j].push_back((i-1)*m+j-1);
                if(j<m&&toca[i][j+1]!=0)
                    adj[(i-1)*m+j].push_back((i-1)*m+j+1);
            }
        }
    }
    cout<<bfs((x-1)*m+y)+1<<"\n";
}
