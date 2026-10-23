#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int h,w,n,med[210][210],di[]={0,0,1,-1},dj[]={1,-1,0,0},id[210][210];
string grid[210];
vector<pair<int,int>> medicines;
vector<int> adj[350];
bool visited[350];
bool valida(int x, int y){
    return (x>=0&&x<h&&y>=0&&y<w&&grid[x][y]!='#');
}
void bfs(int i_ini,int j_ini){
    int dist[210][210];
    for(int y=0;y<h;y++)
        for(int x=0;x<w;x++)
            dist[y][x]=INF;
    queue<pair<int,int>> q;
    dist[i_ini][j_ini]=0;
    q.push(make_pair(i_ini,j_ini));
    while(!q.empty()){
        int i=q.front().first,j=q.front().second;q.pop();
        for(int k=0;k<4;k++)
            if(valida(i+di[k],j+dj[k])&&dist[i+di[k]][j+dj[k]]==INF){
                dist[i+di[k]][j+dj[k]]=dist[i][j]+1;
                q.push(make_pair(i+di[k],j+dj[k]));
            }
    }
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(!(i==i_ini&&j==j_ini)&&med[i][j]!=0&&dist[i][j]<=med[i_ini][j_ini])
                adj[id[i_ini][j_ini]].push_back(id[i][j]);
}
void dfs(int x){
    if(visited[x])return;
    visited[x]=true;
    for(auto u:adj[x])
        dfs(u);
}
int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++)
        cin>>grid[i];
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        med[a-1][b-1]=c;
        id[a-1][b-1]=i+1;
        medicines.push_back(make_pair(a-1,b-1));
    }
    int start,finish;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(grid[i][j]=='S'&&med[i][j]==0){
                cout<<"No\n";
                return 0;
            }else if(grid[i][j]=='S')
                start=id[i][j];
            else if(grid[i][j]=='T'){
                finish=id[i][j];
                med[i][j]=-1;
            }
    for(int k=0;k<(int)medicines.size();k++)
        bfs(medicines[k].first,medicines[k].second);
    dfs(start);
    if(visited[finish])
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}