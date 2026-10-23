#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int di[]={1,-1,0,0},dj[]={0,0,1,-1},n,m,p,comp[maxn][maxn],ans[maxn*maxn];
vector<string> grid;
bool visited[maxn][maxn];
bool posi_valida(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m);
}
void dfs(int i,int j){
    if(visited[i][j])return;
    visited[i][j]=true;
    for(int k=0;k<4;k++)
        if(posi_valida(i+di[k],j+dj[k])){
            comp[i+di[k]][j+dj[k]]=comp[i][j];
            if(grid[i+di[k]][j+dj[k]]=='*')
                ans[comp[i][j]]++;
            else
                dfs(i+di[k],j+dj[k]);
        }
}
int main(){
    cin>>n>>m>>p;
    getchar();
    for(int i=0;i<n;i++){
        string l;
        getline(cin,l);
        grid.push_back(l);
    }
    int c=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visited[i][j]&&grid[i][j]!='*'){
                c++;
                comp[i][j]=c;
                dfs(i,j);
            }
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        cout<<ans[comp[--a][--b]]<<endl;
    }
}