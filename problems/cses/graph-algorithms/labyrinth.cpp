#include <bits/stdc++.h>
using namespace std;
const int MAXN=1050;
int n,m,cont,dist[MAXN][MAXN];
vector<string> grid;
queue<pair<int,int>>q;
bool visited[MAXN][MAXN],found;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char p[MAXN][MAXN];
pair<int,int> dad[MAXN][MAXN],fim,ini;
void bfs(int x, int y){
    visited[x][y]=true;
    q.push(make_pair(x,y));
    while(!q.empty()){
        x=q.front().first;y=q.front().second;q.pop();
        if(grid[x][y]=='B'){
            found=true;
            fim=make_pair(x,y);
        }
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<=n-1&&y+dy[i]>=0&&y+dy[i]<=m-1&&grid[x+dx[i]][y+dy[i]]!='#'&&dad[x][y]!=make_pair(x+dx[i],y+dy[i])&&!visited[x+dx[i]][y+dy[i]]){
                visited[x+dx[i]][y+dy[i]]=true;
                q.push(make_pair(x+dx[i],y+dy[i]));
                dad[x+dx[i]][y+dy[i]]=make_pair(x,y);
                if(i==0)p[x+dx[i]][y+dy[i]]='U';
                if(i==1)p[x+dx[i]][y+dy[i]]='D';
                if(i==2)p[x+dx[i]][y+dy[i]]='L';
                if(i==3)p[x+dx[i]][y+dy[i]]='R';
                dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        grid.push_back(a);
    }
    for(int i=0;i<n;i++)
        for(int k=0;k<m;k++)
            if(grid[i][k]=='A')
                ini=make_pair(i,k);
    dad[ini.first][ini.second]=make_pair(-1,-1);
    bfs(ini.first,ini.second);
    if(found){
        string ans;
        cout<<"YES\n";
        cout<<dist[fim.first][fim.second]<<endl;
        int cont=0;
        while(!(fim.first==ini.first&&fim.second==ini.second)){
            ans.push_back(p[fim.first][fim.second]);
            fim=dad[fim.first][fim.second];
            cont++;
        }
        ans.push_back(p[fim.first][fim.second]);
        for(int i=(int)ans.size()-2;i>=0;i--){
            if(ans[i]=='R')
                cout<<"L";
            else if(ans[i]=='L')
                cout<<"R";
            else if(ans[i]=='U')
                cout<<"D";
            else
                cout<<"U";
        }
        cout<<endl;
    }else
        cout<<"NO\n";
    return 0;
}