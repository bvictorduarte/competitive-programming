/*#include <bits/stdc++.h>
using namespace std;
int d[3]={-1,1};
vector<int> adj[1000050];
int visited[1000050];
void dfs(int x){
    if(visited[x]) return;
    visited[x]=true;
    for(auto s:adj[x])
        dfs(s);
}
int main(){
    int n,m,s;
    ios::sync_with_stdio(false);
	cin.tie(0);
    string map[1050];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>map[i];
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            if(map[i][k]=='#') continue;
            s=m*i+k;
            for(int j=0;j<2;j++)
                if(i+d[j]<=n-1&&i+d[j]>=0&&map[i+d[j]][k]=='.')
                    adj[s].push_back(s+d[j]*m);
            for(int j=0;j<2;j++)
                if(k+d[j]<=m-1&&k+d[j]>=0&&map[i][k+d[j]]=='.')
                    adj[s].push_back(s+d[j]);   
        }
    }
    int cont=0;
    for(int i=0;i<n;i++)
        for(int k=0;k<m;k++){
            s=m*i+k;
            if(visited[s]||map[i][k]=='#')continue;
            cont++;
            dfs(s);
        }
    cout<<cont<<endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+50;
int di[]={-1,1,0,0},dj[]={0,0,1,-1},n,m;
bool visited[maxn][maxn];
vector<string> grid;
void dfs(int i, int j){
    if(visited[i][j])return;
    visited[i][j]=true;
    for(int k=0;k<4;k++){
        int ifilho=i+di[k],jfilho=j+dj[k];
        if(ifilho>=0&&ifilho<n&&jfilho>=0&&jfilho<m&&grid[ifilho][jfilho]=='.')
            dfs(ifilho,jfilho);
    }
}
int main(){
    cin>>n>>m;
    int cont=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        grid.push_back(s);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visited[i][j]&&grid[i][j]!='#'){
                cont++;
                dfs(i,j);
            }
    cout<<cont<<endl;
    return 0;
}