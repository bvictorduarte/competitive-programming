#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
vector<string> grid;
int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
int dist[maxn][maxn];
bool visited[maxn][maxn];
int mod(int a){
    if(a>=0)return a;
    return -a;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string line;
        cin>>line;
        grid.push_back(line);
    }
    int m,p;
    for(m=0;m<n;m++){
        for(p=0;p<n;p++)
            if(grid[m][p]=='*')
                break;
        if(grid[m][p]=='*')
                break;
    }
    queue<pair<int,int>> q;
    q.push(make_pair(m,p));
    visited[m][p]=true;
    while(!q.empty()){
        pair<int,int> s=q.front();q.pop();
        int x=s.first,y=s.second;
        for(int i=0;i<4;i++)
            if(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<n&&grid[x+dx[i]][y+dy[i]]=='*'&&!visited[x+dx[i]][y+dy[i]]){
                dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
                q.push(make_pair(x+dx[i],y+dy[i]));
                visited[x+dx[i]][y+dy[i]]=true;
            }
    }
    bool ans=true;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]=='*')
                if(dist[i][j]!=mod(i-m)+mod(j-p))
                    ans=false;
    if(ans)
        cout<<"S\n";
    else
        cout<<"N\n";
}