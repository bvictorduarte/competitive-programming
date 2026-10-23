#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+50;
int a[maxn][5],b[maxn][5];
int dpa[maxn],dpb[maxn];
void dfs1(int x){
    if(x==0)return;
    if(a[x][1]==0)
        dpa[x]=1;
    else{
        dfs1(a[x][1]);
        dpa[x]=dpa[a[x][1]]+1;
    }
    dfs1(a[x][2]);
}
void dfs2(int x){
    if(x==0)return;
    if(b[x][1]==0)
        dpb[x]=1;
    else{
        dfs2(b[x][1]);
        dpb[x]=dpb[b[x][1]]+1;
    }
    dfs2(b[x][2]);
}
int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        cin>>a[v][2]>>a[v][1];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int v;
        cin>>v;
        cin>>b[v][1]>>b[v][2];
    }
    dfs1(1);
    dfs2(1);
    int m1=-1,m2=-1;
    for(int i=1;i<=n;i++)
        m1=max(m1,dpa[i]);
    for(int i=1;i<=m;i++)
        m2=max(m2,dpb[i]);
    cout<<n+m-(max(min(dpa[1],m2),min(dpb[1],m1)))<<endl;
}