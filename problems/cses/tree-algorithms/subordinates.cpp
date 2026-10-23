#include<bits/stdc++.h>
using namespace std;
const int maxN=2*1e5+50;
vector<int> adj[maxN];
int cont[maxN];
void dfs(int x, int parent){
    cont[x]=1;
    for(auto u:adj[x]){
        if(u==parent)continue;
        dfs(u,x);
        cont[x]+=cont[u];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(1,0);
    cout<<--cont[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<--cont[i];
    cout<<endl;
    return 0;
}