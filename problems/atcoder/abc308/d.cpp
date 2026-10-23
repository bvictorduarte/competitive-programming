#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
string v[maxn],comp;
int di[]={1,-1,0,0},dj[]={0,0,1,-1};
int h,w;
bool found=false,visited[maxn][maxn];
void dfs(int i, int j, int x){
    if(visited[i][j]||found)return;
    visited[i][j]=true;
    if(i==h&&j==w){
        found=true;
        return;
    }
    for(int k=0;k<4;k++)
        if(i+di[k]>=1&&i+di[k]<=h&&j+dj[k]>=1&&j+dj[k]<=w&&comp[(x+1)%5]==v[i+di[k]][j+dj[k]])
            dfs(i+di[k],j+dj[k],(x+1)%5);
}
int main(){
    cin>>h>>w;
    string s;
    comp="snuke";
    for(int i=0;i<=530;i++)
        s.push_back('-');
    v[0]=s;
    for(int i=1;i<=h;i++){
        v[i].push_back('-');
        cin>>s;
        v[i]+=s;
    }
    if(v[1][1]=='s')
        dfs(1,1,0);
    if(found)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}