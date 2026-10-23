#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+100;
const int INF=1e9;
bool visited[maxn][maxn];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1},d1[maxn][maxn],d2[maxn][maxn],sx,sy;
queue< pair<int,int> > q;
string grid[maxn],resp;
char ans[maxn][maxn];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a;
        b='0'+a;
        grid[i]=b;
    }
    for(int i=1;i<maxn;i++)
        for(int j=1;j<maxn;j++){
            d1[i][j]=d2[i][j]=INF;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(grid[i][j]=='M'){
                q.push(make_pair(i,j));
                visited[i][j]=true;
                d1[i][j]=0;
            }else if(grid[i][j]=='A'){
                sx=i;
                sy=j;
                d2[i][j]=0;
                ans[i][j]='0';
            }else if(grid[i][j]=='#'){
                visited[i][j]=true;
                ans[i][j]='0';
            }
    while(!q.empty()){
        int a=q.front().first,b=q.front().second;q.pop();
        for(int i=0;i<4;i++){
            if(a+dx[i]>=1&&a+dx[i]<=n&&b+dy[i]>=1&&b+dy[i]<=m){
                if(visited[a+dx[i]][b+dy[i]]) continue;
                visited[a+dx[i]][b+dy[i]]=true;
                d1[a+dx[i]][b+dy[i]]=d1[a][b]+1;
                q.push(make_pair(a+dx[i],b+dy[i]));
            }
        }
    }
    for(int i=1;i<maxn;i++)
        for(int j=1;j<maxn;j++)
            visited[i][j]=false;
    q.push(make_pair(sx,sy));
    visited[sx][sy]=true;
    while(!q.empty()){
        int a=q.front().first,b=q.front().second;q.pop();
        for(int i=0;i<4;i++){
            if(a+dx[i]>=1&&a+dx[i]<=n&&b+dy[i]>=1&&b+dy[i]<=m){
                if(grid[a+dx[i]][b+dy[i]]=='#')visited[a+dx[i]][b+dy[i]]=true;
                if(visited[a+dx[i]][b+dy[i]]) continue;
                if(i==0){
                    ans[a+dx[i]][b+dy[i]]='D';
                }
                if(i==1){
                    ans[a+dx[i]][b+dy[i]]='U';
                }
                if(i==2){
                    ans[a+dx[i]][b+dy[i]]='R';
                }
                if(i==3){
                    ans[a+dx[i]][b+dy[i]]='L';
                }
                visited[a+dx[i]][b+dy[i]]=true;
                d2[a+dx[i]][b+dy[i]]=d2[a][b]+1;
                q.push(make_pair(a+dx[i],b+dy[i]));
            }
        }
    }
    int a=0,b=0;
    for(int i=1;i<=n;i++)
        if(d1[i][1]>d2[i][1]&&(grid[i][1]=='.'||grid[i][m]=='A')&&d2[i][1]!=INF){
            a=i;
            b=1;
        }
    for(int i=1;i<=n;i++)
        if(d1[i][m]>d2[i][m]&&(grid[i][m]=='.'||grid[i][m]=='A')&&d2[i][m]!=INF){
            a=i;
            b=m;
        }
    for(int i=1;i<=m;i++)
        if(d1[1][i]>d2[1][i]&&(grid[1][i]=='.'||grid[i][m]=='A')&&d2[1][i]!=INF){
            a=1;
            b=i;
        }
    for(int i=1;i<=m;i++)
        if(d1[n][i]>d2[n][i]&&(grid[n][i]=='.'||grid[i][m]=='A')&&d2[n][i]!=INF){
            a=n;
            b=i;
        }
    if(a&&b){
        cout<<"YES"<<endl;
        cout<<d2[a][b]<<endl;
        while(!(a==sx&&b==sy)){
            if(ans[a][b]=='R'){
                resp.push_back('R');
                a+=dx[3];
                b+=dy[3];
            }
            else if(ans[a][b]=='L'){
                resp.push_back('L');
                a+=dx[2];
                b+=dy[2];
            }
            else if(ans[a][b]=='U'){
                resp.push_back('U');
                a+=dx[0];
                b+=dy[0];
            }
            else if(ans[a][b]=='D'){
                resp.push_back('D');
                a+=dx[1];
                b+=dy[1];
            }
        };
        for(int i=(int)resp.size()-1;i>=0;i--)
            cout<<resp[i];
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}