#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+50;
vector<int> adj[maxn];
int prof[maxn],prof_desprot[maxn],prof_radar[maxn],cont;
void dfs(int x, int p, int r){
    prof[x]=prof[p]+1;
    prof_desprot[x]=prof[x];
    for(auto u:adj[x])
        if(u!=p){
            dfs(u,x,r);
            prof_desprot[x]=max(prof_desprot[x],prof_desprot[u]);
            prof_radar[x]=min(prof_radar[x],prof_radar[u]);
        }
    if(prof_desprot[x]+prof_radar[x]-2*prof[x]<=r)
        prof_desprot[x]=-1;
    else if(prof_desprot[x]-prof[x]==r){
        prof_desprot[x]=-1;
        prof_radar[x]=prof[x];
        cont++;
    }
}
int solve(int r){
    cont=0;
    memset(prof_radar,maxn,sizeof(prof_radar));
    dfs(1,-1,r);
    if(prof_desprot[1]!=-1)
        cont++;
    return cont;
}
int n;
int main(){
    int k;
    cin>>n>>k;
    adj[0].push_back(1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int r=0;
    for(int b=maxn/2;b>=1;b/=2)
        while(r+b<=maxn&&solve(r+b)>k)r+=b;
    cout<<++r<<endl;
    return 0;
}