#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> v_comp[maxn];
set<int> s_adj[maxn];
bool visited[maxn];
int comp[maxn],cont=0;
void dfs(int x){
    if(visited[x])return;
    v_comp[comp[x]].push_back(x);
    visited[x]=true;
    for(auto u:s_adj[x]){
        comp[u]=comp[x];
        dfs(u);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        s_adj[a].insert(b);
        s_adj[b].insert(a);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i]){
            cont++;
            comp[i]=cont;
            dfs(i);
        }
    for(int i=1;i<=n;i++){
        if((int)s_adj[i].size()+1!=(int)v_comp[comp[i]].size())
            for(auto u:v_comp[comp[i]]){
                if(u!=i&&s_adj[i].find(u)==s_adj[i].end()){
                    cout<<i<<" "<<u<<endl;
                    return 0;
                }
            }
    }
    cout<<-1<<endl;
    return 0;
}