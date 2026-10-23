/*#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int to_leaf[maxN],maxLenght[maxN];
vector<int> adj[maxN];
void dfs(int x, int s){
    bool neighbor=false;
    for(auto u:adj[x])
        if(u!=s){
            neighbor=true;
            dfs(u,x);
        }
    if(!neighbor)
        to_leaf[x]=0;
    else{
        for(auto u:adj[x])
            to_leaf[x]=max(to_leaf[x],to_leaf[u]);
        to_leaf[x]++;
    }
}
void compute_maxlenght(int x, int s){
    bool neighbor=false;
    int m1=-1,m2=-1,k;
    for(auto u:adj[x])
        if(m1<=to_leaf[u]&&u!=s){
            m1=to_leaf[u];
            k=u;
        }
    for(auto u:adj[x])
        if(k!=u&&u!=s)
            m2=max(m2,to_leaf[u]);
    for(auto u:adj[x])
        if(u!=s){
            neighbor=true;
            compute_maxlenght(u,x);
        }
    if(!neighbor)
        maxLenght[x]=0;
    else
        maxLenght[x]=m1+m2+2;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    if((int)adj[1].size()==1)to_leaf[1]=0;
    compute_maxlenght(1,0);
    int ans=-1;
    for(int i=1;i<=n;i++)
        ans=max(ans,maxLenght[i]);
    cout<<ans<<endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+1;
int v1[maxN],v2[maxN];
vector<int> adj[maxN];
void dfs(int x, int parent, int v[]){
    for(auto u:adj[x])
        if(u!=parent){
            v[u]=v[x]+1;
            dfs(u,x,v);
        }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    v1[1]=0;
    dfs(1,0,v1);
    int maxi=-1,index;
    for(int i=1;i<=n;i++)
        if(maxi<v1[i]){
            maxi=v1[i];
            index=i;
        }
    dfs(index,0,v2);
    maxi=-1;
    for(int i=1;i<=n;i++)
        maxi=max(maxi,v2[i]);
    cout<<maxi<<endl;
    return 0;
}



























