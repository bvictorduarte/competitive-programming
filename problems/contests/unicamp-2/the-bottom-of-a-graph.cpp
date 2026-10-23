#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+50;
vector<int> adj[maxn][5],adj_scc[maxn],scc[maxn];
stack<int> post;
bool visited[maxn][5];
int comp[maxn],out_degree[maxn];
void dfs(int v, int p){
    if(visited[v][p])return;
    visited[v][p]=true;
    for(auto u:adj[v][p]){
        if(p==2&&!comp[u]){
            comp[u]=comp[v];
            scc[comp[u]].push_back(u);
        }
        dfs(u,p);
    }
    if(p==1)    
        post.push(v);
}
int main(){
    int n;
    while(cin>>n&&n){
        for(int i=1;i<maxn;i++){
            adj_scc[i].clear();
            scc[i].clear();
            comp[i]=0;
            out_degree[i]=0;
            for(int j=1;j<=2;j++){
                adj[i][j].clear();
                visited[i][j]=false;
            }
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a][1].push_back(b);
            adj[b][2].push_back(a);
        }
        for(int i=1;i<=n;i++)
            if(!visited[i][1])
                dfs(i,1);
        int c=0;
        while(!post.empty()){
            int a=post.top();post.pop();
            if(!visited[a][2]){
                comp[a]=++c;
                scc[comp[a]].push_back(a);
                dfs(a,2);
            }
        }
        for(int i=1;i<=n;i++)
            for(auto u:adj[i][1])
                if(comp[u]!=comp[i])
                    out_degree[comp[i]]++;
        vector<int> ans,resp;
        for(int i=1;i<=c;i++)
            if(!out_degree[i])
                ans.push_back(i);
        for(auto u:ans)
            for(auto v:scc[u])
                resp.push_back(v);
        sort(resp.begin(),resp.end());
        if((int)resp.size()>0)
            cout<<resp[0];
        for(int i=1;i<(int)resp.size();i++)
            cout<<" "<<resp[i];
        cout<<endl;
    }
    return 0;
}