#include <bits/stdc++.h>
using namespace std;
string grid[150];
int d[3]={1,-1};
int main(){
    int n,m,xini,yini;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>grid[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='o'){
                xini=i;
                yini=j;
            }
        }
    }
    int vdx=xini,vdy=yini;
    bool ainda_anda=true;
    do{
        ainda_anda=false;
        for(int i=0;i<2;i++)
            if(xini+d[i]>=0&&xini+d[i]<=n-1&&grid[xini+d[i]][yini]&&!(xini+d[i]==vdx&&yini==vdy)&&grid[xini+d[i]][yini]!='.'){
                vdx=xini;
                vdy=yini;
                xini+=d[i];
                ainda_anda=true;
                break;
            }
        for(int i=0;i<2;i++)
            if(yini+d[i]>=0&&yini+d[i]<=m-1&&grid[xini][yini+d[i]]&&!(yini+d[i]==vdy&&xini==vdx)&&grid[xini][yini+d[i]]!='.'){
                vdx=xini;                
                vdy=yini;
                yini+=d[i];
                ainda_anda=true;
                break;
            }

    }while(ainda_anda);
    cout<<++xini<<" "<<++yini<<endl;
    return 0;
}