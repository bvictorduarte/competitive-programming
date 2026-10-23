#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> adj[maxn],ans;
int state[maxn],reached,reacha;
void dfs(int a){
    if(reached)
        return;
    if(state[a]==1){
        state[a]=2;
        reached=a;
        ans.push_back(a);
        return;
    }
    if(state[a]==2)
        return;
    state[a]=1;
    for(auto u:adj[a])
        dfs(u);
    if(reached&&!reacha){
        ans.push_back(a);
        if(reached==a)
            reacha=true;
    }
    state[a]=2;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d", &a,&b);
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(reached)
            break;
        if(!state[i])
            dfs(i);
    }
    if(!reached){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    int tam=(int)ans.size();
    cout<<tam<<endl;
    cout<<ans[tam-1];
    for(int i=tam-2;i>=0;i--)
        cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}