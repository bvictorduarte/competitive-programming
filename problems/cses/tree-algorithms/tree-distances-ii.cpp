#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
vector<int> adj[maxn];
long long d[maxn],prof[maxn],children[maxn],n;
void dfs(int x,int p){
    prof[x]=prof[p]+1;
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x);
            children[x]+=children[u];
        }
}
void find_distance(int x, int p){
    for(auto u:adj[x])
        if(u!=p){
            d[u]=n-2*children[u]+d[x];
            find_distance(u,x);
        }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        children[i]=1;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    prof[0]=-1;
    dfs(1,0);
    for(int i=2;i<=n;i++)
        d[1]+=prof[i];
    find_distance(1,0);
    cout<<d[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<d[i];
    cout<<endl;
    return 0;
}