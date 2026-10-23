#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
stack<int> s;
vector<int> adj[5][maxn];
bool visited[5][maxn];
void dfs(int x, int p){
    if(visited[p][x])return;
    visited[p][x]=true;
    for(auto u:adj[p][x])
        dfs(u,p);
    if(p==1)
        s.push(x);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[1][a].push_back(b);
        adj[2][b].push_back(a);
        adj[3][a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        if(!visited[1][i])
            dfs(i,1);
    vector<int> ans;
    while(!s.empty()){
        if(!visited[2][s.top()]){
            ans.push_back(s.top());
            dfs(s.top(),2);
        }
        s.pop();
    }
    if((int)ans.size()==1)
        cout<<"YES\n";
    else{
        cout<<"NO\n";
        dfs(ans[0],3);
        if(visited[ans[1]])
            swap(ans[0],ans[1]);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}