#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
bool found;
vector<int> adj[maxn];
int visited[maxn],pai[maxn],k,u;
void dfs(int x, int p=0){
    if(visited[x]==1){
        found=true;
        u=x;
        k=p;
    }
    if(visited[x]||found)return;
    visited[x]=1;
    for(auto u:adj[x])
        if(u!=p){
            if(!pai[u])
                pai[u]=x;
            dfs(u,x);
        }
    visited[x]=2;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i])
            dfs(i);
    if(!found)
        cout<<"IMPOSSIBLE\n";
    else{
        int aux=k,cont=0;
        do{
            aux=pai[aux];
            cont++;
        }while(aux!=u);
        cout<<cont+2<<endl;
        cout<<u;
        do{
            cout<<" "<<k;
            k=pai[k];
        }while(k!=u);
        cout<<" "<<u<<endl;
    }
    return 0;
}