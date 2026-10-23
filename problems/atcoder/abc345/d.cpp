#include<bits/stdc++.h>
using namespace std;
const int maxw=15;
const int maxh=15;
const int maxn=10;
int grid[maxw][maxh],a[maxn],b[maxn],usados=0,n,w,h;
vector<pair<int,int>> points;
bool solve(int usados, int curposi){
    int curi=points[curposi].first,curj=points[curposi].second;
    if(grid[curi][curj]==1&&curposi==h*w)
        return true;
    if(grid[curi][curj]==1)
        return solve(usados,curposi+1);
    for(int u=1;u<=n;u++){
        if(usados^(1<<u))continue;
        usados|=(1<<u);
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                grid[curi+i][curj+j]=1;
        
    }

}
int main(){
    cin>>n>>h>>w;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for(int i=1;i<=h;i++)
        for(int j=1;j<=h;j++){
            grid[i][j]=0;
            points.push_back({i,j});
        }
    return 0;
}