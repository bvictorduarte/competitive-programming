#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+50;
vector<int> adj[MAXN],top_sort;
int in_degree[MAXN],visited[MAXN];
bool have_cycle;
void dfs(int x){
    if(visited[x]==1){
        have_cycle=true;
        return;
    }else if(visited[x]==2)return;
    visited[x]=1;
    for(auto u:adj[x])
        dfs(u);
    visited[x]=2;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++)
        if(in_degree[i]==0)
            pq.push(i);
    for(int i=1;i<=n;i++)
        if(visited[i]==0)
            dfs(i);
    if(have_cycle){
        cout<<"Sandro fails.\n";
        return 0;
    }
    while(!pq.empty()){
        int x=pq.top();pq.pop();
        top_sort.push_back(x);
        for(auto u:adj[x]){
            in_degree[u]--;
            if(in_degree[u]>0)continue;
            pq.push(u);
        }
    }
    cout<<top_sort[0];
    for(int i=1;i<n;i++)
        cout<<" "<<top_sort[i];
    cout<<endl;
    return 0;
}