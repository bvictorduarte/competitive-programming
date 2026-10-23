#include<bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1},n,m,k;
char grid[40][40];
bool visited[40][40];
void dfs(int l, int c){
    if(visited[l][c])
        return;
    visited[l][c]=true;
    for(int i=0;i<4;i++)
        if(l+dx[i]>=1&&l+dx[i]<=n&&c+dy[i]>=1&&c+dy[i]<=m&&grid[l+dx[i]][c+dy[i]]=='.')
            dfs(l+dx[i],c+dy[i]);
}
int main(){
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            grid[i][j]='.';
    char dir;
    int lc,cc;
    for(int i=1;i<=k;i++){
        cin>>cc>>lc>>dir;
        if(dir=='O')
            for(int j=cc;j>=1;j--)
                grid[lc][j]='#';
        if(dir=='L')
            for(int j=cc;j<=m;j++)
                grid[lc][j]='#';
        if(dir=='N')
            for(int j=lc;j>=1;j--)
                grid[j][cc]='#';
        if(dir=='S')
            for(int j=lc;j<=n;j++)
                grid[j][cc]='#';
    }
    dfs(1,1);
    if(!visited[n][m]||grid[1][1]=='#')
        cout<<"N\n";
    else
        cout<<"S\n";

}