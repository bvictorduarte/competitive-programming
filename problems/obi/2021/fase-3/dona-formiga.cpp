#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+1;
vector<int> adj[maxn];
int dist1[maxn],prof1[maxn],prof2[maxn];
bool visited[maxn];
void dfs1(int x, int p){
    for(auto u:adj[x])
        if(u!=p){
            prof1[u]=prof1[x]+1;
            dfs1(u,x);
        }
}
void dfs2(int x,int p){
    for(auto u:adj[x])
        if(u!=p){
            prof2[u]=prof2[x]+1;
            dfs2(u,x);
        }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    int m=-1;
    for(auto u:prof1)
        m=max(m,u);
    int cont1=0,k;
    for(int i=1;i<=n;i++)
        if(prof1[i]==m){
            cont1++;
            k=i;
            visited[i]=true;
        }
    dfs2(k,0);
    int c=-1;
    for(auto u:prof2)
        c=max(c,u);
    int cont2=0,cont3=0;
    for(int i=1;i<=n;i++)
        if(prof2[i]==c&&!visited[i])
            cont2++;
        else if(prof2[i]==c)
            cont3++;
    cout<<c+1<<endl<<cont1*cont2+((cont1*cont3)/2)<<endl;
    return 0;
}