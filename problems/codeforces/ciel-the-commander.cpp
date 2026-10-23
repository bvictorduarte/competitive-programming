#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int sz[maxn];
char ans[maxn];
vector<int> adj[maxn];
bool removed[maxn];
int find_distances(int x, int p=0){
    sz[x]=1;
    for(auto u:adj[x])
        if(u!=p&&!removed[u])
            sz[x]+=find_distances(u,x);
    return sz[x];
}
int find_centroid(int x, int tam, int p=0){
    for(auto u:adj[x])
        if(u!=p&&!removed[u]&&2*sz[u]>tam)
            return find_centroid(u,tam,x);
    return x;
}
void decompose(int x=1, int p=0, char c='A'){
    int centroid=find_centroid(x,find_distances(x));
    removed[centroid]=true;
    ans[centroid]=c;
    for(auto u:adj[centroid])
        if(!removed[u]&&u!=p)
            decompose(u,centroid,(char)(c+1));
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decompose();
    cout<<ans[1];
    for(int i=2;i<=n;i++)
        cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}