/*#include<bits/stdc++.h>
using namespace std;
int n,m,cont=0;
int di[]={-1,1,0,0},dj[]={0,0,-1,1};
bool cord_valida(int i, int j){
    if(i>=0&&i<m&&j>=0&&j<n)
        return true;
    return false;
}
int main(){
    string mapa[1050];
    cin>>m>>n;
    for(int i=0;i<m;i++)
        cin>>mapa[i];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(mapa[i][j]=='#')
                for(int k=0;k<4;k++)
                    if((cord_valida(i+di[k],j+dj[k])&&mapa[i+di[k]][j+dj[k]]=='.')||!cord_valida(i+di[k],j+dj[k])){
                        cont++;
                        break;
                    }
    cout<<cont<<endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+50;
int di[]={1,-1,0,0},dj[]={0,0,1,-1},n,m;
string grid[maxn];
bool visited[maxn][maxn];
bool cord_valida(int i, int j){
    if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]=='#')
        return true;
    return false;
}
void dfs(int l, int c){
    if(visited[l][c])
        return;
    visited[l][c]=true;
    for(int i=0;i<4;i++)
        if(cord_valida(l+di[i],c+dj[i]))
            dfs(l+di[i],c+dj[i]);
}
int main(){
    cin>>n>>m;
    int cont=0;
    for(int i=0;i<m;i++)
        cin>>grid[i];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(!visited[i][j]&&grid[i][j]=='#'){
                cont++;
                dfs(i,j);
            }
    cout<<cont<<endl;
    return 0;
}