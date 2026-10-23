#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100050];
int distancia[100050],veio_de[100050];
bool visited[100050];
stack<int> ans;
queue<int>q;
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d", &a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int s=q.front();q.pop();
        for(auto u:adj[s]){
            if(visited[u])continue;
            veio_de[u]=s;
            distancia[u]=distancia[s]+1;
            q.push(u);
            visited[u]=true;
        }
    }
    if(distancia[n]==0){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    cout<<distancia[n]+1<<endl;
    int u=n;
    for(int k=1;k<=distancia[n]+1;k++){
        ans.push(u);
        u=veio_de[u];
    }
    while(!ans.empty()){
        printf("%d ", ans.top());
        ans.pop();
    }
    cout<<endl;
}