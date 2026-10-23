#include<bits/stdc++.h>
using namespace std;
const int maxn=250;
int di[]={0,0,1,-1},dj[]={1,-1,0,0},h,l,comp[maxn][maxn],quant[maxn*maxn];
int grid[maxn][maxn];
bool visited1[maxn][maxn],visited2[maxn][maxn];
void dfs1(int v,int i, int j){
    if(visited1[i][j])return;
    visited1[i][j]=true;
    for(int k=0;k<4;k++)
        if(i+di[k]<=h&&i+di[k]>=1&&j+dj[k]<=l&&j+dj[k]>=1&&grid[i+di[k]][j+dj[k]]==v){
            comp[i+di[k]][j+dj[k]]=comp[i][j];
            dfs1(v,i+di[k],j+dj[k]);
        }
}
int main(){
    cin>>h>>l;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=l;j++){
            cin>>grid[i][j];
        }
    int cont=0;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=l;j++)
            if(!visited1[i][j]){
                cont++;
                comp[i][j]=cont;
                dfs1(grid[i][j],i,j);
            }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=l;j++)
            quant[comp[i][j]]++;
    int ans=maxn*maxn;
    for(int i=1;i<=cont;i++)
        ans=min(ans,quant[i]);
    cout<<ans<<endl;
    return 0;
}