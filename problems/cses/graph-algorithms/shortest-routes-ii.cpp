#include<bits/stdc++.h>
using namespace std;
const int MAXN=550;
const long long INF=1e18+50;
long long adj[MAXN][MAXN];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(adj[i][j]==0&&i!=j)
                adj[i][j]=INF;
            else if(i==j)
                adj[i][j]=0;
    }
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                adj[j][k]=min(adj[j][k],adj[i][k]+adj[j][i]);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(adj[a][b]!=INF)
            cout<<adj[a][b]<<endl;
        else
            printf("-1\n");
    }
    return 0;
}