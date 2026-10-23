#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
const int INF=1e9;
vector<pair<int,pair<int,int>>> edges;
int link[maxn],size[maxn],value[maxn];
vector<pair<int,int>> adj[maxn];
bool visited[maxn];
int find(int a){
    while(a!=link[a])a=link[a];
    return a;
}
bool same(int a, int b){
    return find(a)==find(b);
}
void unite(int a, int b){
    a=find(a);
    b=find(b);
    if(size[b]<size[a])swap(a,b);
    link[a]=b;
    size[b]+=size[a];
}
void dfs(int x,int p){
    if(visited[x])return;
    visited[x]=true;
    for(auto u:adj[x]){
        int a=u.first,w=u.second;
        if(a!=p){
            value[a]=min(value[x],w);
            dfs(a,x);
        }
    }
}
int main(){
    int n,m,i=0;
    while(cin>>n>>m&&!(n==0&&m==0)){
        ++i;
        edges.clear();
        for(int i=1;i<=n;i++){
            link[i]=i;
            size[i]=1;
            visited[i]=false;
            adj[i].clear();
        }
        for(int i=0;i<m;i++){
            int a,b,w;
            cin>>a>>b>>w;
            w--;
            edges.push_back(make_pair(w,make_pair(a,b)));
        }
        int s,d,t;
        cin>>s>>d>>t;
        sort(edges.rbegin(),edges.rend());
        for(auto edge:edges){
            int a=edge.second.first,b=edge.second.second;
            if(!same(a,b)){
                unite(a,b);
                adj[a].push_back(make_pair(b,edge.first));
                adj[b].push_back(make_pair(a,edge.first));
            }
        }
        value[s]=INF;
        dfs(s,0);
        cout<<"Scenario #"<<i<<'\n';
        cout<<"Minimum Number of Trips = ";
        if(t%value[d]==0)
            cout<<t/value[d];
        else
            cout<<(t/value[d])+1;
        cout<<"\n\n";
    }
    return 0;
}