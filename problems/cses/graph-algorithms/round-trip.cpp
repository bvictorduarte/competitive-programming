#include <bits/stdc++.h>
using namespace std;
const int NMAX=1e5+50;
vector<int> adj[NMAX];
int dad[NMAX],ini,fim;
bool visited[NMAX],found;
void dfs(int x){
    for(auto u:adj[x]){
        if(visited[u]){
            if(!found&&u!=dad[x]){
                found=true;
                ini=x;
                fim=u;
            }
            continue;
        }
        visited[u]=true;
        dad[u]=x;
        dfs(u);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,c;
        cin>>a>>c;
        adj[a].push_back(c);
        adj[c].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        visited[i]=true;
        dfs(i);
    }
    if(found){
        int ini1=ini,fim1=fim,cont=0;
        while(ini1!=fim1){
            ini1=dad[ini1];
            cont++;
        }
        cout<<cont+2<<endl;
        cout<<fim<<" ";
        while(ini!=fim){
            cout<<ini<<" ";
            ini=dad[ini];
        }
        cout<<fim<<endl;

    }else
        cout<<"IMPOSSIBLE\n";
    return 0;
}